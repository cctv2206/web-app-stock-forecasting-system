<?PHP
    class YahooFinance {
    static function CurrentPrice($stock)//this function gets current price information, input should be an array of stock symoble
        {
    if (is_array($stock)) { // if it's array save them for query the yahoo finance link
                $stockquery = implode(',', $stock);
    }
            
            /********some useful tag*******/
            /*
             s0:symbol;
             n0:name;
             l1:current price;
             d1:last trade date;
             t1 last trade time
             c1 change
             h0 days high
             g0 days low
             w0 year range
            */
            /*****************************/
    $stockFormat = "sl1vd1t1";
            // 5 para to retrive: symbole, price,volume, trade date, trade time
    $host = "http://quote.yahoo.com/d/quotes.csv";
    $requestUrl = $host."?s=".$stockquery."&f=".$stockFormat."&e=.csv";//query the API and get the data
    
    // get VSC RAW data
    $filesize=2000;
    $handle = fopen($requestUrl, "r");
    $raw = fread($handle, $filesize); //save the data
    fclose($handle);
    // Split results, delete the quotation marks, trim way the extra line break at the end
    $quotes = explode("\n",trim($raw));
    $s=str_replace('"', '', $quotes);
    for($i=0;$i<count($stock);$i++){
    $stock[$i]=explode(',',$s[$i]);
    }
            return $stock;
        }
    static function HistoryPrice($stock){ // this function use to retrieve history stock information from 2014 to 2015. input should be a specific stock symbol
        $requestUrl ="http://ichart.yahoo.com/table.csv?s=".$stock."&a=1&b=1&c=2014&d=1&e=31&f=2015&g=d&ignore=.csv";
        $filesize=200000;
        $handle=file_get_contents($requestUrl);
       
        // Split results, delete the quotation marks, trim way the extra line break at the end
        $quotes = explode("\n",trim($handle));
       
        for($i=1;$i<365;$i++){
            $stock1[$i]=explode(',',$quotes[$i]);
        }
        
        for($i=0;$i<200;$i++){
            // echo $i;
            for($j=0;$j<7;$j++){
                // echo $j;
                echo $stock1[$i][$j]." ";}
            echo "<br>";
        }
            return $stock1;

        }
        
        
   
    }
?>