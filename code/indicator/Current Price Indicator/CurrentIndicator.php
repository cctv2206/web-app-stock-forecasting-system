//written by Yue Wu
//debugged by Yue Wu
<?PHP
    require_once('IndicatorAPI.php');
    $con = mysqli_connect("localhost", "root", "shmily", "StockForecasting"); //link to the database
    if (!$con)
    {
        die('Could not connect: ' . mysql_error());
    } // create table currentprice to save data.
    
    $sql = "CREATE TABLE IF NOT EXISTS CurrentIndicator
    (
     ID INT(6)  NOT NULL AUTO_INCREMENT PRIMARY KEY,
     Stock VARCHAR(15),
     SMA  DECIMAL(10,3),
     EMA DECIMAL(10,3),
     CAMD DECIMAL(10,3)
     )ENGINE=MyISAM";
    if (mysqli_query($con, $sql)) {
        echo "Table CURRENTINDICATOR created successfully"."<br>";
    } else {
        echo "Error creating table: " . mysqli_error($con);
    }
    $arr = array("AMZN","AAPL","FB","GOOG","YHOO","SIRI","GE","S","BAC","MSFT");
    do{
    for($i=0;$i<count($arr);$i++){
    $camd=Indicator::MACD($arr[$i]);
    //if($camd==-3) continue;
    $camd=end($camd);
    echo $camd."<br>";
    $sma=Indicator::SMA($arr[$i]);
    //if($sma==-3) continue;
    $sma=end($sma);
    echo $sma;
    $ema=Indicator::EMA($arr[$i]);
    $ema=end($ema);
   // while($i<count($sma)){
   // $id=mysqli_insert_id($con)+1;
        $sql= mysqli_query($con,"Insert INTO CurrentIndicator (Stock,SMA,CAMD,EMA)
                           VALUES ('$arr[$i]','$sma','$camd','$ema')
                          ");
                           }
                          
                         sleep(60);
                          }while(true);
                          // echo "last insert ID".mysqli_insert_id($con)+1;
                           mysqli_close($con);

    ?>