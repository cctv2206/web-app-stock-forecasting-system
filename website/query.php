<?php

class query{

//query1 Show the list of all companies in the database along with their latest stock price.
     static function query1($stock){
        
        $con = mysqli_connect("localhost", "root", "root", "StockForecasting"); //link to the database
        if (!$con)
        {
            die('Could not connect: ' . mysql_error());
        } // creat table currentprice to save data.
         
         $sql="SELECT * FROM $stock";
        if (mysqli_query($con, $sql)) {
            //echo "Selecting successfully"."<br>";
        } else {
            echo "Error: " . mysqli_error($con);
        }
        $i=0;
        
        $result=mysqli_query($con,$sql);
        if (mysqli_num_rows($result) > 0) {
            // output data of each row
            while($row = mysqli_fetch_assoc($result)) {
         
            $sid[$i]=$row['Stocks'];
            $pid[$i]=$row['Price'];
            $tid[$i]=$row['Time'];
            $i++;
          
            }
        } else {
            echo "0 results";
        }
       
        for ($i=1;$i<10;$i++){
        echo "Stock: ".$sid[$i];
        echo "<br>";
        echo "Price  ".$pid[$i];
        echo "<br>";
        echo "Time   ".$tid[$i];
        echo "<br>";
        echo "<br>";
        }
        
    }

//query2 Get the highest stock price of Google in the last ten days
     static function query2($stock){
        
        $con = mysqli_connect("localhost", "root", "root", "StockForecasting"); //link to the database
        if (!$con)
        {
            die('Could not connect: ' . mysql_error());
        } // creat table currentprice to save data.
        
        $sql="SELECT * FROM $stock";
        if (mysqli_query($con, $sql)) {
            //echo "Selecting successfully"."<br>";
        } else {
            echo "Error: " . mysqli_error($con);
        }

        $result=mysqli_query($con,$sql);
        $i=0;
        if (mysqli_num_rows($result) > 0) {
            // output data of each row
            while($row = mysqli_fetch_assoc($result)) {
            
                $data[$i]=$row['Close'];
                $date[$i]=$row['Date'];
                $i++;
            }
        } else {
            echo "0 results";
        }
        $highest=$data[0];
        $highestdate=$date[0];

        for ($i=1;$i<10;$i++){
        
            if($data[$i]>$highest)
            {
            $highest=$data[$i];
            $highestdate=$date[$i];
            }
        }
        echo "The highest price of ".$stock." in ten days is ".$highest. " in ".$highestdate;
        echo "<br>";
    }
    


  //query3 Average stock price of Microsoft in the latest one year
     static function query3($stock){
        
        $con = mysqli_connect("localhost", "root", "root", "StockForecasting"); //link to the database
        if (!$con)
        {
            die('Could not connect: ' . mysql_error());
        } // creat table currentprice to save data.
        
        $sql="SELECT * FROM $stock";
        if (mysqli_query($con, $sql)) {
            //echo "Selecting successfully"."<br>";
        } else {
            echo "Error: " . mysqli_error($con);
        }

        $result=mysqli_query($con,$sql);
        $i=0;
        if (mysqli_num_rows($result) > 0) {
            // output data of each row
            while($row = mysqli_fetch_assoc($result)) {
            
                $data[$i]=$row['Close'];
                $i++;
            }
        } else {
            echo "0 results";
        }
        $average=$data[0];
      
        
        for ($i=1;$i<count($data);$i++){
        
            $average=$average+$data[$i];
        }
        $average=$average/count($data);
        
        
        return $average;
    }
    

    //query4 Lowest stock price for each company in the latest one year
    static function query4($stock){
        
        $con = mysqli_connect("localhost", "root", "root", "StockForecasting"); //link to the database
        if (!$con)
        {
            die('Could not connect: ' . mysql_error());
        } // creat table currentprice to save data.
        
        $sql="SELECT * FROM $stock";
        if (mysqli_query($con, $sql)) {
            //echo "Selecting successfully"."<br>";
        } else {
            echo "Error: " . mysqli_error($con);
        }

        $result=mysqli_query($con,$sql);
        $i=0;
        if (mysqli_num_rows($result) > 0) {
            // output data of each row
            while($row = mysqli_fetch_assoc($result)) {
            
                $data[$i]=$row['Close'];
                $date[$i]=$row['Date'];
                $i++;
            }
        } else {
            echo "0 results";
        }
        $lowest=$data[0];
        $lowestdate=$date[0];
        
        for ($i=1;$i<count($data);$i++){
            if($data[$i]<$lowest)
            {
            $lowest=$data[$i];
            $lowestdate=$date[$i];
            }
        }
        echo "the lowest price of ".$stock." is ".$lowest;
        echo "<br>";
        echo "the date of lowest price is ".$lowestdate;
        echo "<br>";
    }  
    
    static function query5($stock){
    	$company[0]="Amazon";
        $company[1]="Apple";
        $company[2]="BAC";
        $company[3]="FaceBook";
        $company[4]="GE";
        $company[5]="Google";
        $company[6]="Mcirosoft";
        $company[7]="SIRI";
        $company[8]="Sprint";
        $company[9]="Yahoo";
        echo "The company whose average price in last year is less than ".$stock." is:";
        echo "<br>";
        echo "<br>";
        
        for($i=0;$i<10;$i++)
        {
        	$price[$i]=query::query3($company[$i]);
        	if ($price[$i]<query::query3($stock))
        	{
        	echo $company[$i];
        	echo "<br>";
        	echo"Average price: ".$price[$i];
        	echo "<br>";
        	echo "<br>";
        	}
        }
      
        
  
        
        
    }  
}
?>

