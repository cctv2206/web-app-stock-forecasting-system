/**

 * Writtern by Wuyang Zhang
 * Debugged by Wuyang Zhang
 * Test by Wuyang Zhang
 */
import java.sql.*;
import java.io.*;

public class StockPredict {
    static final String JDBC_DRIVER = "com.mysql.jdbc.Driver";
    static final String DB_URL = "jdbc:mysql://localhost/StockForecasting";
    static final String USER = "root";
    static final String PASSWORD = "root";
    static final int recentN = 30;
    static final int shortN = 200;
    static final String FILE_NAME = "/Users/Wuyang/Desktop/machineL/java/C_price_";
    static final String Predict_FILE_NAME = "/Users/Wuyang/Desktop/machineL/java/C_predict_";
    static final String PredictPrice_FILE_NAME = "/Users/Wuyang/Desktop/machineL/java/C_predictPrice_"    ;
    static final String SH_FILE_NAME = "/Users/Wuyang/Desktop/machineL/java/sh";

    static final String H_FILE_NAME = "/Users/Wuyang/Desktop/machineL/java/H_price_";
    static final String H_Predict_FILE_NAME = "/Users/Wuyang/Desktop/machineL/java/H_predict_";
    static final String H_PredictPrice_FILE_NAME = "/Users/Wuyang/Desktop/machineL/java/H_predictPrice_"    ;
    static final String H_SH_FILE_NAME = "/Users/Wuyang/Desktop/machineL/java/H_sh";
    /*
        File:
        C_price30_AAPL documenting recent price in N day;
        C_predict30_AAPL documenting only data that is necessary to predict
        C_predictPrice_AAPL

     */
    static class Price {
        public String current;
        public String open;
        public String close;
    }
    static class SQLHistoryData{
        private String url;
        private Connection conn;
        private Statement stmt;
        private PreparedStatement ps;
        public Price[] price;
        public Price[] priceComp;
        private int dayN;
        private int predictLength;

        private String ticker_table(String ticker){
            if(ticker == "AAPL")
                return "Apple";
            else if(ticker == "BAC")
                return "BAC";
            else if(ticker =="AMZN")
                return "Amazon";
            else if(ticker == "FB")
                return "FB";
            else if(ticker == "GE")
                return "GE";
            else if(ticker == "GOOG")
                return "Google";
            else if(ticker == "MSFT")
                return "Mcirosoft";
            else if(ticker == "SIRI")
                return "SIRI";
            else if(ticker == "S")
                return "Sprint";
            else if(ticker == "YHOO")
                return "Yahoo";
            else
                return null;
        }


        public SQLHistoryData(String url, int dayN, int predictLength) throws IOException{
            try{
                this.url = url;
                this.dayN = dayN;
                this.predictLength = predictLength;

                Class.forName(JDBC_DRIVER);
                conn = DriverManager.getConnection(DB_URL, USER, PASSWORD);
                stmt = conn.createStatement();
//                init price array
                price = new Price[dayN+predictLength];
                for (int i = 0; i < dayN+predictLength; i++) {
                    price[i] = new Price();
                }
                /*


                 ps = conn.prepareStatement("SELECT Price from CurrentPrice  WHERE Stocks = ? LIMIT ? ");
                ps.setString (1,url);
                ps.setInt(2, this.dayN);
                ps.executeQuery();
                ResultSet currentPrice = ps.executeQuery();
                 */
                ps = conn.prepareStatement("SELECT Open FROM History WHERE Stocks = ? LIMIT ?");
//                ps = conn.prepareStatement("SELECT Open FROM ?  WHERE Stocks = ? LIMIT ? ");
                ps.setString(1, url);
                ps.setInt(2,this.dayN);
                ResultSet openPrice = ps.executeQuery();
                /*
//                ps.setString(1,url);
                ps.setString(1, ticker_table(url));
                ps.setString (2, url);
                ps.setInt(3, this.dayN);
                ps.executeQuery();
                ResultSet openPrice = ps.executeQuery();
                */
                int nn = 0;
                while (openPrice.next()) {
                    String open = openPrice.getString(1);
                    price[nn].open = open;
                    nn++;
                }
                // get close price;

                ps = conn.prepareStatement("SELECT Close FROM History  WHERE Stocks = ? LIMIT ? ");
//                ps.setString(1,ticker_table(url));
                ps.setString(1, url);
                ps.setInt(2, this.dayN + this.predictLength);
                ps.executeQuery();
                ResultSet closePrice = ps.executeQuery();
                nn = 0;
                while(closePrice.next()){
                    String close = closePrice.getString(1);
                    price[nn].close = close;
                    nn++;
                }

                //save data to file

                PrintWriter w = new PrintWriter(H_FILE_NAME + url + predictLength);

                for ( int i = 0 ; i< dayN; i++) {

                    w.println(price[i].open + " 1:" + price[i + predictLength].close );
                }

                PrintWriter w2 = new PrintWriter(H_Predict_FILE_NAME + url + predictLength);

                    w2.println("111 1:"+ price[0].close);


                PrintWriter sh = new PrintWriter(H_SH_FILE_NAME + url + predictLength +".sh");
                sh.print("which java"+ "\n" +
                                "cd /Users/Wuyang/Desktop/machineL/java/" + "\n" +
                                " java -classpath libsvm.jar svm_scale -l 0 -u 1 -s H_price_" + url +predictLength+ "ScaleP H_price_" + url + predictLength +" > H_price_" +url +predictLength+"Scale" + "\n" +
                                "java -classpath libsvm.jar svm_train -s 3 -t 2 -c 1 -g 1  H_price_" + url +predictLength+"Scale" + "\n" +
                                "java -classpath libsvm.jar svm_scale -r H_price_" + url +predictLength+ "ScaleP" + " H_predict_" + url +predictLength+" > H_predict_"+url+predictLength+"Scale" + "\n" +
                                "java -classpath libsvm.jar svm_predict H_predict_" + url +predictLength+"Scale H_price_"+ url +predictLength+"Scale.model H_predictPrice_"+url+predictLength
                );

                sh.close();
                w.close();
                w2.close();

                //read predict value into database
                FileReader file = new FileReader(H_PredictPrice_FILE_NAME+url+predictLength);
                BufferedReader reader;
                String predictprice = "";
                try{
                    reader = new BufferedReader(file);
                    predictprice = reader.readLine();
                    double pricevalue = Double.parseDouble(predictprice);
                    if(predictLength == 0)
                        ps = conn.prepareStatement("INSERT INTO Predict  (Stocks,NextDay) VALUES(?,?) ");
                    else if(predictLength == 6)
                        ps = conn.prepareStatement("INSERT INTO Predict  (Stocks,NextWeek) VALUES(?,?) ");
                    else if (predictLength == 29)
                        ps = conn.prepareStatement("INSERT INTO Predict  (Stocks,NextMonth) VALUES(?,?) ");
                    ps.setString(1,url);
                    ps.setDouble(2, pricevalue);
                    ps.executeUpdate();
                }catch(Exception e){
                    e.printStackTrace();
                }
                file.close();
            }catch (Exception e){
                e.printStackTrace();
            }
        }
    }



    static class SQLCurrentData {
        //read history data // write history data
        private String url;
        private Connection conn;
        private Statement stmt;
        private PreparedStatement ps;
        public Price[] price;
        public Price[] priceComp;
        private int dayN;



        public SQLCurrentData(String url) throws IOException {
            try {
                this.url = url;
                this.dayN = 100; //total 420 suggested 300
//                connect to database
                Class.forName(JDBC_DRIVER);
                conn = DriverManager.getConnection(DB_URL, USER, PASSWORD);
                stmt = conn.createStatement();
//                init price array
                price = new Price[dayN];
                for (int i = 0; i < dayN; i++) {
                    price[i] = new Price();
                }
//              get recent 200 price from current data, set data in price[]

                ps = conn.prepareStatement("SELECT Price from CurrentPrice  WHERE Stocks = ? LIMIT ? ");
                ps.setString (1,url);
                ps.setInt(2, this.dayN);
                ps.executeQuery();
                ResultSet currentPrice = ps.executeQuery();

                int nn = 0;
                while (currentPrice.next()) {
                    String current = currentPrice.getString(1);
                    price[nn].current = current;
                    nn++;
                }
                //compared data in recent 201 days , set data in priceComp[]
                priceComp = new Price[dayN+1];
                for (int i = 0; i< dayN+1; i++){
                    priceComp[i] = new Price();
                }
                ps = conn.prepareStatement("SELECT Price from CurrentPrice WHERE Stocks = ? LIMIT ?");
                ps.setString(1,url);
                ps.setInt(2,this.dayN+1);
                currentPrice = ps.executeQuery();
                nn =0;
                while (currentPrice.next()){
                    String current = currentPrice.getString(1);
                    priceComp[nn].current = current;
                    nn++;
                }
                //save data to file
                for( int i = 0; i< this.dayN; i++){
                    System.out.println(price[i].current + " "+ priceComp[i+1].current);
                }
                PrintWriter w = new PrintWriter(FILE_NAME + url);

                for ( int i = 0 ; i< dayN; i++) {

                    w.println(price[i].current + " 1:" + priceComp[i+1].current );
                }

                PrintWriter w2 = new PrintWriter(Predict_FILE_NAME + url);

                    w2.println("111 1:"+ price[0].current);



                PrintWriter sh = new PrintWriter(SH_FILE_NAME + url + ".sh");
                sh.print("which java"+ "\n" +
                        "cd /Users/Wuyang/Desktop/machineL/java/" + "\n" +
                                " java -classpath libsvm.jar svm_scale -l 0 -u 1 -s C_price_" + url + "ScaleP C_price_" + url +" > C_price_" +url +"Scale" + "\n" +
                        "java -classpath libsvm.jar svm_train -s 3 -t 2 -c 1 -g 1  C_price_" + url +"Scale" + "\n" +
                        "java -classpath libsvm.jar svm_scale -r C_price_" + url + "ScaleP" + " C_predict_" + url +" > C_predict_"+url+"Scale" + "\n" +
                        "java -classpath libsvm.jar svm_predict C_predict_" + url +"Scale C_price_"+ url +"Scale.model C_predictPrice_"+url
                );
                sh.close();
                w.close();
                w2.close();
                //read predict price into database
                FileReader file = new FileReader(PredictPrice_FILE_NAME+url);
                BufferedReader reader;
                String predictprice = "";
                try{
                    reader = new BufferedReader(file);
                    predictprice = reader.readLine();
                    double pricevalue = Double.parseDouble(predictprice);

                    ps = conn.prepareStatement("INSERT INTO Predict (Stocks,Minute) VALUES(?,?) ");
                    ps.setString(1, url);
                    ps.setDouble(2,pricevalue);
                    ps.executeUpdate();
                }catch(Exception e){
                    e.printStackTrace();
                }
                file.close();

            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }

    public static void main(String args[])throws IOException {
        try {
            String [] stock = {"AMZN","AAPL","BAC","FB","GE","GOOG","MSFT","SIRI","S","YHOO"};
            for(int i =0 ; i<stock.length; i++){
                new SQLCurrentData( stock[i] );
                new SQLHistoryData(stock[i],30,0);
                new SQLHistoryData(stock[i],30,6);
                new SQLHistoryData(stock[i],30,29);
            }

        }catch (Exception e){
            e.printStackTrace();
        }


    }
}

