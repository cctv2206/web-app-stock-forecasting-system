//written by Yue Wu
//Assisted by Wuyang Zhang
//debugged by Yue Wu
<?php
    require_once('YahooAPI.php');
    include_once 'class/dbConnect.php';
    $db = new dbConnect();
    $con = mysqli_connect($db->getHost(), $db->getUser(), $db->getPassword(), $db->getDB());
    date_default_timezone_set(EST);
     mysqli_query($con,"delete from History");

    //. The historical data should at least contain time, open, high, low, close, volume
    // crate table
    $sql = "CREATE TABLE History
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

    mysqli_query($con,$sql);
    
    $stock = array("AMZN","AAPL","FB","GOOG","YHOO","BAC","GE","MSFT","SIRI","S");

    for($stockID =0;$stockID<count($stock);$stockID++){
        $day =0;
        $stockPrice = YahooFinance::HistoryPrice($stock[$stockID],0);
        for($day = 0;$day<365;$day++){
            mysqli_query($con,"INSERT INTO History(Stocks, Open, High, Low, Close, Volume, Date)
                       VALUES ('$stock[$stockID]','{$stockPrice[$day][1]}','{$stockPrice[$day][2]}','{$stockPrice[$day][3]}','{$stockPrice[$day][4]}','{$stockPrice[$day][5]}','{$stockPrice[$day][0]}')");
            
        }
    }
    mysqli_close($con);
                           
?>
