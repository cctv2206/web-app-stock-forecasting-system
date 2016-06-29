<?php
// Writtern by Wuyang Zhang
//Debugged by Wuyang Zhang
//Test by Wuyang Zhang
	$con = mysqli_connect("localhost","root","root","StockForecasting");
	$sql = "SELECT Open,Close,Low,High,Volume FROM GE LIMIT 90 ";
	$result = mysqli_query($con,$sql);
	$resultArray = array();
	$tempArray = array();
	while($row = $result->fetch_object()){
		$tempArray = $row;
		array_push($resultArray,$tempArray);
	}
	echo json_encode($resultArray);
	mysqli_close($con);

?>