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
	  FROM SIRI
	  ORDER BY Date ASC";
	$result = mysql_query( $query );

	$query1 = "
	SELECT *
	FROM SIRIIndicator
	ORDER BY ID DESC";
	$result1 = mysql_query($query1);

	// All good?
	if ( !($result and $result1) ) {
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
		if ($count < 26)
		{
			$count += 1;
			continue;
		}
		$rowI = mysql_fetch_assoc( $result1 );
	  echo $prefix . " {\n";
	  echo '  "date": "' . $row['Date'] . '",' . "\n";
	  echo '  "open": ' . $row['Open'] . ',' . "\n";
	  echo '  "close": ' . $row['Close'] . ',' . "\n";
	  echo '  "high": ' . $row['High'] . ',' . "\n";
	  echo '  "low": ' . $row['Low'] . ',' . "\n";
	  echo '  "volume": ' . $row['Volume'] . ',' . "\n";
	  echo '  "value": ' . $row['Open'] . ',' . "\n";

	  echo '  "SMA": ' . $rowI['SMA'] . ',' . "\n"; // indicators
	  echo '  "EMA": ' . $rowI['EMA'] . ',' . "\n";
	  echo '  "MFI": ' . $rowI['MFI'] . ',' . "\n";
	  echo '  "CAMD": ' . $rowI['CAMD'] . ',' . "\n";
	  echo '  "RSI": ' . $rowI['RSI'] . '' . "\n";
	  echo " }";
	  $prefix = ",\n";
	}
	echo "\n]";

	// Close the connection
	mysql_close($link);
?> 