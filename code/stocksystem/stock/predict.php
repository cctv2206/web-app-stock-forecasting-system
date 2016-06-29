<?php
// Writtern by Wuyang Zhang
//Debugged by Wuyang Zhang
//Test by Wuyang Zhang
	$con = mysqli_connect("localhost", "root","root","StockForecasting");
	$sql = "CREATE TABLE IF NOT EXISTS Predict
			(
				ID INT(6) NOT NULL AUTO_INCREMENT PRIMARY KEY,
				Stocks VARCHAR(15),
				Minute DECIMAL(10,3),
				NextDay DECIMAL (10,3),
				NextWeek DECIMAL(10,3),
				NextMonth DECIMAL (10,3)

				)ENGINE = MyISAM";
	 if (mysqli_query($con, $sql)) {
        echo "Table Predict created successfully"."<br>";
    } else {
        echo "Error creating table: " . mysqli_error($con);
    }
     mysqli_close($con);
?>