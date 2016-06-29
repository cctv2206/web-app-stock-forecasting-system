//written by Yue Wu
//debugged by Yue Wu
<?PHP
    require_once('Indicator.php');
    $time=1;
    $sma=Indicator::SMA("Amazon");
    //echo $test;
    /*for ($i=0;$i<20;$i++){
     echo $sma[$i];
     echo "<br>";
     }*/
    $ema=Indicator::EMA("Amazon");
    $mfi=Indicator::MFI("Amazon");
    $camd=Indicator::MACD("Amazon");
    $rsi=Indicator::RSI("Amazon");
    
    
    date_default_timezone_set(EST);
    $con = mysqli_connect("localhost", "root", "", "StockForecasting"); //link to the database
    if (!$con)
    {
        die('Could not connect: ' . mysql_error());
    } // create table currentprice to save data.
    
    $sql = "CREATE TABLE IF NOT EXISTS AmazonIndicator
    (
     ID INT(6)  NOT NULL AUTO_INCREMENT PRIMARY KEY,
     Stock VARCHAR(15),
     SMA  DECIMAL(10,3),
     EMA DECIMAL(10,3),
     MFI DECIMAL(10,3),
     CAMD DECIMAL(10,3),
     RSI DECIMAL(10,3)
     )ENGINE=MyISAM";
    if (mysqli_query($con, $sql)) {
        echo "Table AmazonINDICATOR created successfully"."<br>";
    } else {
        echo "Error creating table: " . mysqli_error($con);
    }
    $del="DELETE FROM AmazonIndicator";
    if(mysqli_query($con,$del))echo "Record deleted successfully";
    else {
        echo "Error deleting record: " . mysqli_error($con);
    }

    $i=0;
    // insert history data into the table
    while($i<count($ema)){
        $sql= mysqli_query($con,"Insert INTO AmazonIndicator (Stock,SMA,EMA,MFI,CAMD,RSI)
                           VALUES ('Amazon','$sma[$i]','$ema[$i]','$mfi[$i]','$camd[$i]','$rsi[$i]')");
                           $i++;
                           }
                           
                           $time=1;
                           do{
                           $sma=Indicator::SMA("Amazon");
                           $ema=Indicator::EMA("Amazon");
                           $mfi=Indicator::MFI("Amazon");
                           $camd=Indicator::MACD("Amazon");
                           $rsi=Indicator::RSI("Amazon");
                           
                           
                           $t=0;
                           while($t<count($ema)){
                           $sql= mysqli_query($con,"UPDATEAmazonIndicator SET SMA='$sma[$t]',MFI='$mfi[$t]',EMA='$ema[$t]',CAMD='$camd[$t]',RSI='$rsi[$t]'
                                              WHERE ID='$t'");
                                              $t++;
                                              }
                                              sleep(86400);
                                              }while(true);
                                              
                                              mysqli_close($con);
                                              
    ?>
