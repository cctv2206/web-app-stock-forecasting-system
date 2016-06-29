<?php
class Indicator{
    //predict price for SMA and EMA all use five past days

    //SMA
    static function SMA($stock){
        
        $con = mysqli_connect("localhost", "root", "root", "StockForecasting"); //link to the database
        if (!$con)
        {
            die('Could not connect: ' . mysql_error());
        } // creat table currentprice to save data.
        
        $sql="SELECT Close FROM $stock ";
        if (mysqli_query($con, $sql)) {
            echo "Selecting successfully"."<br>";
        } else {
            echo "Error: " . mysqli_error($con);
        }

        $result=mysqli_query($con,$sql);
        $i=0;
        if (mysqli_num_rows($result) > 0) {
            // output data of each row
            while($row = mysqli_fetch_assoc($result)) {
               // echo "close: " . $row['Close']. "<br>";
                $data[$i]=$row['Close'];
                $i++;
            }
        } else {
            echo "0 results";
        }
        for ($i=0;$i<(count($data)-5);$i++){
            $sma[$i]=($data[$i]+$data[$i+1]+$data[$i+2]+$data[$i+3]+$data[$i+4])/5;
        }
        echo "the size of sma is: ".count($sma);
        echo "<br>";
         return $sma;
    }
    //EMA
    static function EMA($stock){
        $alpha=2/(5+1);
        echo "alpha is: ".$alpha."<br>";
        $con = mysqli_connect("localhost", "root", "root", "StockForecasting"); //link to the database
        if (!$con)
        {
            die('Could not connect: ' . mysql_error());
        } // creat table currentprice to save data.
        
        $sql="SELECT Close FROM $stock";
        if (mysqli_query($con, $sql)) {
            echo "Selecting successfully"."<br>";
        } else {
            echo "Error: " . mysqli_error($con);
        }
        
        $result=mysqli_query($con,$sql);
        $i=0;
        if (mysqli_num_rows($result) > 0) {
            // output data of each row
            while($row = mysqli_fetch_assoc($result)) {
                // echo "close: " . $row['Close']. "<br>";
                $data[$i]=$row['Close'];
               // echo "data is: ".$data[$i];
                $i++;
            }
        } else {
            echo "0 results";
        }
        echo "<br>";
        for ($i=0;$i<(count($data)-5);$i++){
            $ema[$i]=$alpha*($data[$i]*pow((1-$alpha),4)+$data[$i+1]*pow((1-$alpha),3)+$data[$i+2]*pow((1-$alpha),2)+$data[$i+3]*pow((1-$alpha),1)+$data[$i+4]);
          //  echo "the ema is: ".$ema[$i];
           // echo "<br>";
        }
        echo "the size of ema is: ".count($ema);
        echo "<br>";
        return $ema;
        
        
    }//EMA END
    
    //MFI
    //Predict price for MFI use past 14 days typical price
    static function MFI($stock){
        $con = mysqli_connect("localhost", "root", "root", "StockForecasting"); //link to the database
        if (!$con)
        {
            die('Could not connect: ' . mysql_error());
        } // creat table currentprice to save data.
        
        $sql="SELECT * FROM $stock";
        if (mysqli_query($con, $sql)) {
            echo "Selecting successfully"."<br>";
        } else {
            echo "Error: " . mysqli_error($con);
        }
        
        $result=mysqli_query($con,$sql);
        $i=0;
        if (mysqli_num_rows($result) > 0) {
            // output data of each row
            while($row = mysqli_fetch_assoc($result)) {
                // echo "close: " . $row['Close']. "<br>";
                $high[$i]=$row['High'];
                $low[$i]=$row['Low'];
                $close[$i]=$row['Close'];
                $volume[$i]=$row['Volume'];
                $TypicalPrice[$i]=($high[$i]+$low[$i]+$close[$i])/3;
                $MoneyFlow[$i]=$TypicalPrice[$i]*$volume[$i];
               // echo "data is: ".$MoneyFlow[$i];
                $i++;
            }
        } else {
            echo "0 results";
        }
    
        for ($i=0;$i<(count($high)-14);$i++){
            // initial positive money flow and negative money flow
            $PMF=0;
            $NMF=0;
           
            for($t=13;$t>=0;$t--){
                if($MoneyFlow[$i+$t]>$MoneyFlow[$i+$t-1]){
                    $PMF+=$MoneyFlow[$i+$t+1];
                }else{
                    $NMF+=$MoneyFlow[$i+$t+1];
                }
            }
            $MoneyRatio=$PMF/$NMF;
          
            $mfi[$i]=100-100/(1+$MoneyRatio);
            //echo "mfi: ".$mfi[$i]."<br>";
        }
        echo "the size of mfi is: ".count($mfi);
        echo "<br>";
        return $mfi;
        
    }//MFI END
    
   //use past 26 and 12 days price
    static function MACD($stock){
        
        
        $alpha1=2/(12+1);
        $alpha2=2/(26+1);
        echo "alpha is: ".$alpha."<br>";
        $con = mysqli_connect("localhost", "root", "root", "StockForecasting"); //link to the database
        if (!$con)
        {
            die('Could not connect: ' . mysql_error());
        } // creat table currentprice to save data.
        
        $sql="SELECT Close FROM $stock";
        if (mysqli_query($con, $sql)) {
            echo "Selecting successfully"."<br>";
        } else {
            echo "Error: " . mysqli_error($con);
        }
        
        $result=mysqli_query($con,$sql);
        $i=0;
        if (mysqli_num_rows($result) > 0) {
            // output data of each row
            while($row = mysqli_fetch_assoc($result)) {
                // echo "close: " . $row['Close']. "<br>";
                $data[$i]=$row['Close'];
                // echo "data is: ".$data[$i];
                $i++;
            }
        } else {
            echo "0 results";
        }
        echo "<br>";
        for ($i=0;$i<(count($data)-12);$i++){
            $temp=0;
            for($t=12;$t>0;$t--){
                $temp+=$alpha1*($data[$i+$t]*pow(1-$alpha1,$t-1));
            }
            $ema12[$i]=$temp;
        }
          for ($i=0;$i<(count($data)-26);$i++){
                $temp=0;
                for($t=26;$t>0;$t--)
                $temp+=$alpha2*($data[$i+$t]*pow(1-$alpha2,$t-1));
                           $ema26[$i]=$temp;
            }
                                for ($i=0;$i<count($ema26);$i++){
                                $dif[$i]=$ema12[$i+14]-$ema26[$i];
                                }
        echo "the size of dif is: ".count($dif);
        echo "<br>";
                                return $dif;
        
    }//MACD END
    
    
   //RSI
    //calculate 10 days ave up and dow Close price
    static function RSI($stock){
        
        $con = mysqli_connect("localhost", "root", "root", "StockForecasting"); //link to the database
        if (!$con)
        {
            die('Could not connect: ' . mysql_error());
        } // creat table currentprice to save data.
        
        $sql="SELECT Close FROM $stock";
        if (mysqli_query($con, $sql)) {
            echo "Selecting successfully"."<br>";
        } else {
            echo "Error: " . mysqli_error($con);
        }
        
        $result=mysqli_query($con,$sql);
        $i=0;
        if (mysqli_num_rows($result) > 0) {
            // output data of each row
            while($row = mysqli_fetch_assoc($result)) {
                // echo "close: " . $row['Close']. "<br>";
                $data[$i]=$row['Close'];
                $i++;
            }
        } else {
            echo "0 results";
        }
        for($i=0;$i<(count($data)-10);$i++){
            for($t=0;$t<10;$t++){
                $dif=$data[$i+$t+1]-$data[$i+$t];
                if($dif>=0)
                    $upclose[$t]=$dif;
                else
                    $downclose[$t]=-$dif;
            }
            $RS=(array_sum($upclose)/count($upclose))/(array_sum($downclose)/count($downclose));
            $RSI[$i]=100-100/(1+$RS);
            
        }
        echo "the size of RIS is: ".count($RSI);
        echo "<br>";
        return $RSI;

    
    }//RSI END
    

    //ADL
    static function ADL($stock){
        
        $con = mysqli_connect("localhost", "root", "root", "StockForecasting"); //link to the database
        if (!$con)
        {
            die('Could not connect: ' . mysql_error());
        } // creat table currentprice to save data.
        
        $sql="SELECT * FROM $stock";
        if (mysqli_query($con, $sql)) {
            echo "Selecting successfully"."<br>";
        } else {
            echo "Error: " . mysqli_error($con);
        }

        $result=mysqli_query($con,$sql);
        $i=0;
        
        if (mysqli_num_rows($result) > 0) {
            // output data of each row
            while($row = mysqli_fetch_assoc($result)) {
               // echo "close: " . $row['Close']. "<br>";
                $high[$i]=$row['High'];
                //echo $high[$i];
                $low[$i]=$row['Low'];
                $close[$i]=$row['Close'];
                $volume[$i]=$row['Volume'];
                $i++;
            }
        } else {
            echo "0 results";
        }
        
       for ($i=0;$i<(count($close)-1);$i++){
            //calculate the money flow multipler
       // echo ($low[$i]);
            $multipler=(($close[$i]-$low[$i])-($high[$i]-$close[$i]))/($high[$i]-$low[$i]);
            //echo $multipler;
            //calculate the flow volume
            $flow_vol=$multipler*$volume[$i];
           // echo $flow_vol;
            //calculate the ADL
            if($i==0){
                $adl[$i]=$flow_vol;

            }
            else{
                $adl[$i]=$adl[$i-1]+$flow_vol;
                
            }
            
        }
       // echo "the size of adl is: ".count($adl);
        echo "<br>";
        return $adl;
         
    }//ADL END

             //OBV
    static function OBV($stock){
        
        $con = mysqli_connect("localhost", "root", "root", "StockForecasting"); //link to the database
        if (!$con)
        {
            die('Could not connect: ' . mysql_error());
        } // creat table currentprice to save data.
        
        $sql="SELECT * FROM $stock";
        if (mysqli_query($con, $sql)) {
            echo "Selecting successfully"."<br>";
        } else {
            echo "Error: " . mysqli_error($con);
        }

        $result=mysqli_query($con,$sql);
        $i=0;
        
        if (mysqli_num_rows($result) > 0) {
            // output data of each row
            while($row = mysqli_fetch_assoc($result)) {
               // echo "close: " . $row['Close']. "<br>";
                $high[$i]=$row['High'];
                //echo $high[$i];
                $low[$i]=$row['Low'];
                $close[$i]=$row['Close'];
                $volume[$i]=$row['Volume'];
                $i++;
            }
        } else {
            echo "0 results";
        }

        
        
       for ($i=0;$i<(count($close)-1);$i++){
            //calculate the current obv
                if($close[$i]>$close[$i-1]){
                    $obv[$i]=$obv[$i-1]+$volume[$i];
                }
                else if($close[$i]<$close[$i-1]){
                    $obv[$i]=$obv[$i-1]-$volume[$i];
                }
                else{
                    $obv[$i]=$obv[$i-1];
                }
        }
        
        
       // echo "the size of adl is: ".count($obv);
        echo "<br>";
        return $obv;
         
    }//OBV END
    
    
    //BB
    static function BB($stock){
        
        $con = mysqli_connect("localhost", "root", "root", "StockForecasting"); //link to the database
        if (!$con)
        {
            die('Could not connect: ' . mysql_error());
        } // creat table currentprice to save data.
        
        $sql="SELECT * FROM $stock";
        if (mysqli_query($con, $sql)) {
            echo "Selecting successfully"."<br>";
        } else {
            echo "Error: " . mysqli_error($con);
        }

        $result=mysqli_query($con,$sql);
        $i=0;
        if (mysqli_num_rows($result) > 0) {
            // output data of each row
            while($row = mysqli_fetch_assoc($result)) {
               // echo "close: " . $row['Close']. "<br>";
                $data[$i]=$row['Close'];
                $i++;
            }
        } else {
            echo "0 results";
        }
        

        for ($i=0;$i<(count($data)-20);$i++){
            $sample[0]=$data[$i];
            $sample[1]=$data[$i+1];
            $sample[2]=$data[$i+2];
            $sample[3]=$data[$i+3];
            $sample[4]=$data[$i+4];
            $sample[5]=$data[$i+5];
            $sample[6]=$data[$i+6];
            $sample[7]=$data[$i+7];
            $sample[8]=$data[$i+8];
            $sample[9]=$data[$i+9];
            $sample[10]=$data[$i+10];
            $sample[11]=$data[$i+11];
            $sample[12]=$data[$i+12];
            $sample[13]=$data[$i+13];
            $sample[14]=$data[$i+14];
            $sample[15]=$data[$i+15];
            $sample[16]=$data[$i+16];
            $sample[17]=$data[$i+17];
            $sample[18]=$data[$i+18];
            $sample[19]=$data[$i+19];

            //get the standard deviation value
            
            if(is_array($sample)){
            $mean = array_sum($sample) / count($sample);
            foreach($sample as $key => $num) $devs[$key] = pow($num - $mean, 2);
            }

            $std[$i]=sqrt(array_sum($devs) / (count($devs) - 1));

            $sma[$i]=($data[$i]+$data[$i+1]+$data[$i+2]+$data[$i+3]+$data[$i+4]
                     +$data[$i+5]+$data[$i+6]+$data[$i+7]+$data[$i+8]+$data[$i+9]
                     +$data[$i+10]+$data[$i+11]+$data[$i+12]+$data[$i+13]+$data[$i+14]
                     +$data[$i+15]+$data[$i+16]+$data[$i+17]+$data[$i+18]+$data[$i+19])/20;
            $band_mid[$i]=$sma[$i];

            $band_upp[$i]=$sma[$i]+2*$std[$i];

            $band_low[$i]=$sma[$i]-2*$std[$i];
            $bb[$i]=$sma[$i];

            $bb[$i+count($data)-1]=$sma[$i]+2*$std[$i];
            $bb[$i+2*count($data)-1]=$sma[$i]-2*$std[$i];
            // echo $bb;
        }
        
        //echo "the size of sma is: ".count($sma);
        echo "<br>";
        //return $band_mid;
        return $bb;
    }
    
    
    
}
?>

