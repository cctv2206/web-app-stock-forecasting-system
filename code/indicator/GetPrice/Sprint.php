//written by Yue Wu
//debugged by Yue Wu
<?PHP
    require_once('YahooAPI.php');
    date_default_timezone_set(EST);
    $con = mysqli_connect("localhost", "root", "shmily", "StockForecasting");
    if (!$con)
    {
        die('Could not connect: ' . mysql_error());
    }
    //. The historical data should at least contain time, open, high, low, close, volume
    $sql = "CREATE TABLE IF NOT EXISTS Sprint
    (
     ID INT(6)  NOT NULL AUTO_INCREMENT PRIMARY KEY,
     Stocks VARCHAR(15),
     Open  DECIMAL(10,3),
     High DECIMAL(10,3),
     Low DECIMAL(10,3),
     Close DECIMAL(10,3),
     Volume INT(10),
     Date VARCHAR(20) DEFAULT '0'
     )ENGINE=MyISAM";
    if (mysqli_query($con, $sql)) {
        echo "Table Sprint created successfully"."<br>";
    } else {
        echo "Error creating table: " . mysqli_error($con);
    }
    
    $arr = "S";
    $del="DELETE FROM Sprint";
    if(mysqli_query($con,$del))echo "Record deleted successfully";
    else {
        echo "Error deleting record: " . mysqli_error($con);
    }

    
    //$arr1 = array("STEM","COOL","RENN","DRYS","KCG","GOOG","NVDA","RAD");
    //$volume[] = 0;
    $i=0;
    $arrprice = YahooFinance::HistoryPrice($arr,0);
    while($i<365){
        //$volumechange=($arrprice[$i][2]-$volume[$i]);
        //$volume[$i]=$arrprice[$i][2];
        $sql= mysqli_query($con,"INSERT INTO Sprint(Stocks, Open, High, Low, Close, Volume, Date)
                           VALUES ('$arr','{$arrprice[$i][1]}','{$arrprice[$i][2]}','{$arrprice[$i][3]}','{$arrprice[$i][4]}','{$arrprice[$i][5]}','{$arrprice[$i][0]}')");
                           $i++;
                           }
                           
                           $date=1;
                           //do{
                           $i=0;
                           $arrprice = YahooFinance::HistoryPrice($arr,$date);
                           while($i<365){
                           $sql= mysqli_query($con,"UPDATE Sprint SET Open='{$arrprice[$i][1]}', High='{$arrprice[$i]  [2]}',Low='{$arrprice[$i][3]}', Close='{$arrprice[$i][4]}', Volume='{$arrprice[$i][5]}', Date='{$arrprice[$i][0]}'
                                              WHERE ID='$i'");
                                              $i++;
                                              $date++;
                                              if($date==30)$date=1;
                                              
                                              }
                                              sleep (86400);
                                              // }while(true);

                           mysqli_close($con);
                           
                           ?>
