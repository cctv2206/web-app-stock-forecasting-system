<?php
	// Connect to MySQL
	$link = mysql_connect( 'localhost', 'root', 'root' );
	if ( !$link ) {
	  die( 'Could not connect: ' . mysql_error() );
	}

	// Select the data base
	$db = mysql_select_db( 'StockForecasting', $link );
	if ( !$db ) {
	  die ( 'Error selecting database \'StockForecasting\' : ' . mysql_error() );
	}

	// Fetch the data
	$query = "
	  SELECT *
	  FROM CurrentPrice
	  WHERE Stocks = 'YHOO' 
	  ORDER BY ID ASC";
	$result = mysql_query( $query );

	$query1 = "
	  SELECT *
	  FROM CurrentIndicator
	  WHERE Stock = 'YHOO' 
	  ORDER BY ID ASC";
	$result1 = mysql_query( $query1 );

	// All good?
	if ( !$result ) {
	  // Nope
	  $message  = 'Invalid query: ' . mysql_error() . "\n";
	  $message .= 'Whole query: ' . $query;
	  die( $message );
	}

	// Print out rows
	$prefix = '';
	$count = 0;
	echo "[\n";
	while ( $row = mysql_fetch_assoc( $result ) ) {
		if ($count < 27)
		{
			$count += 1;
			continue;
		}
		$row1 = mysql_fetch_assoc( $result1 );
	  echo $prefix . " {\n";
	  echo '  "Time": "' . substr($row['Time'], 0, -1) . '",' . "\n";
	  echo '  "Price": ' . $row['Price'] . ',' . "\n";
	  echo '  "Volume": ' . $row['VolumeChange'] . ',' . "\n";

	  echo '  "SMA": ' . $row1['SMA'] . ',' . "\n";
	  echo '  "EMA": ' . $row1['EMA'] . ',' . "\n";
	  echo '  "CAMD": ' . $row1['CAMD'] . '' . "\n";
	  echo " }";
	  $prefix = ",\n";
	}
	echo "\n]";

	// Close the connection
	mysql_close($link);
?> 