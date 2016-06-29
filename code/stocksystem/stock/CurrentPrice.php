<?PHP
    require_once('YahooAPI.php');
    date_default_timezone_set(EST);
    //ignore_user_abort(); // if this set on, the PHP will run background. Now set to off.
   set_time_limit(0);
    $con = mysqli_connect("localhost", "root", "shmily", "StockForecasting"); //link to the database
    if (!$con)
    {
        die('Could not connect: ' . mysql_error());
    } // creat table currentprice to save data.
    $sql = "CREATE TABLE IF NOT EXISTS CurrentPrice
    (
     ID INT(6)  NOT NULL AUTO_INCREMENT PRIMARY KEY,
     Stocks VARCHAR(15),
     Price DECIMAL(10,3),
     Volume int(10),
     VolumeChange int(10),
     Date VARCHAR(20) DEFAULT '0',
     Time Varchar(20) Default '0'
         )ENGINE=MyISAM";
    if (mysqli_query($con, $sql)) {
        echo "Table CurrentPrice created successfully"."<br>";
    } else {
        echo "Error creating table: " . mysqli_error($con);
    }
    
    $arr = array("AMZN","AAPL","FB","GOOG","YHOO"); // use to get current price information

    $volume[] = 0;
   // do{
    $i=0;
    $arrprice = YahooFinance::CurrentPrice($arr);
   
    //insert the result into table
    while($i<count($arr)){
        $volumechange=($arrprice[$i][2]-$volume[$i]);
        $volume[$i]=$arrprice[$i][2];
    $sql= mysqli_query($con,"INSERT INTO CurrentPrice (Stocks, Price, Volume,VolumeChange,Date,Time)
                       VALUES ('{$arrprice[$i][0]}','{$arrprice[$i][1]}','{$arrprice[$i][2]}','$volumechange','{$arrprice[$i][3]}','{$arrprice[$i][4]}')");
                       $i++;
    }
    
    for($i=0;$i<count($arr);$i++)
    for($j=0;$j<5;$j++)
    echo $arrprice[$i][$j]."<br>";
                       sleep(30);//update the database every 30 seconds.
                      }while  (true);
    mysqli_close($con);
    
    ?>
