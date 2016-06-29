//written by Yue Wu
//debugged by Yue Wu
<?php
    class Indicator{
        //predict price for SMA and EMA all use five past days
        
        //SMA
        static function SMA($stock){
            
            $con = mysqli_connect("localhost", "root", "shmily", "StockForecasting"); //link to the database
            if (!$con)
            {
                die('Could not connect: ' . mysql_error());
            } // creat table currentprice to save data.
            
            $sql="SELECT Price FROM CurrentPrice WHERE Stocks='$stock' ORDER BY ID";//$stock should use the symbol name
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
                    $data[$i]=$row['Price'];
                    $i++;
                }
            } else {
                echo "0 results";
            }
            if (count($data)<5) return -3;
            //return $data;/*
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
            $con = mysqli_connect("localhost", "root", "shmily", "StockForecasting"); //link to the database
            if (!$con)
            {
                die('Could not connect: ' . mysql_error());
            } // creat table currentprice to save data.
            
            $sql="SELECT Price FROM CurrentPrice WHERE Stocks='$stock' ORDER BY ID";
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
                    $data[$i]=$row['Price'];
                    // echo "data is: ".$data[$i];
                    $i++;
                }
            } else {
                echo "0 results";
            }
            if (count($data)<5) return -3;

            echo "<br>";
            
            for ($i=0;$i<(count($data)-5);$i++){
                $ema[$i]=$alpha*($data[$i]*pow((1-$alpha),4)+$data[$i+1]*pow((1-$alpha),3)+$data[$i+2]*pow((1-$alpha),2)+$data[$i+3]*pow((1-$alpha),1)+$data[$i+4]);
                //  echo "the ema is: ".$ema[$i];
                // echo "<br>";
            }
            
            return $ema;
            
            
        }//EMA END
        
        //MFI
        //Predict price for MFI use past 14 days typical price
        static function MFI($stock){
            $con = mysqli_connect("localhost", "root", "shmily", "StockForecasting"); //link to the database
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
            return $mfi;
            
        }//MFI END
        
        
        static function MACD($stock){
            
            
            $alpha1=2/(12+1);
            $alpha2=2/(26+1);
            echo "alpha is: ".$alpha."<br>";
            $con = mysqli_connect("localhost", "root", "shmily", "StockForecasting"); //link to the database
            if (!$con)
            {
                die('Could not connect: ' . mysql_error());
            } // creat table currentprice to save data.
            
            $sql="SELECT Price FROM CurrentPrice WHERE Stocks='$stock' ORDER BY ID";
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
                    $data[$i]=$row['Price'];
                    // echo "data is: ".$data[$i];
                    $i++;
                }
            } else {
                echo "0 results";
            }
            if(count($data)<27)return -3;
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
            return $dif;
            
        }//MACD END
        
        
        //RSI
        //calculate 10 days ave up and dow Close price
        static function RSI($stock){
            
            $con = mysqli_connect("localhost", "root", "shmily", "StockForecasting"); //link to the database
            if (!$con)
            {
                die('Could not connect: ' . mysql_error());
            } // creat table currentprice to save data.
            
            $sql="SELECT Price FROM CurrentPrice WHERE Stocks='$stock' ORDER BY ID";
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
                    $data[$i]=$row['Price'];
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
            return $RSI;
            
            
        }//RSI END
        
        
        
    }
    ?>

