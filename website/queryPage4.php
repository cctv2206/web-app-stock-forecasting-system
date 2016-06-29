<?php
require_once('query.php');

?>


<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" lang="en">

<head>
  <meta http-equiv="Content-Type" content="text/html; charset=utf-8"/> 
  
  <title> Stock Forecasting - Home</title>
  
  <link rel="stylesheet" type="text/css" href="css/style.css" />
  <script type="text/javascript" src="js/jquery.js"></script>
  <script type="text/javascript" src="js/apple.js"></script>
  
  

</head>


<body>
<div id="wrapper">

  <div id="header"><!-- Start Header -->
    <span id="number">Stock Forecasting </span>
  </div><!-- End Header -->
  
  <div id="tryThis" style="height: 37px">
    <ul id="nav-home"> <!-- Navigation -->
      <li><a href="index.html">Home</a></li>
      <li><a href="login.html">My Stocks</a></li>
      <li><a href="queryPage1.php">Query1</a></li>
      <li><a href="queryPage2.php">Query2</a></li>
      <li><a href="queryPage3.php">Query3</a></li>
      <li><a href="queryPage4.php">Query4</a></li>
      <li><a href="queryPage5.php">Query5</a></li>
    </ul>
  </div>
  <br>
  <br>
  <br>

  <div id='hahaha'  style="background-color:#f2f2f2;  width:100%">
    <?php
    echo "<br>";
    echo "Lowest stock price for each company in the latest one year";
    echo "<br>";
    echo "<br>";
      $test1=query::query4("Amazon");
    echo "<br>";
    
    $test2=query::query4("Apple");
    echo "<br>";
    
    $test3=query::query4("BAC");
    echo "<br>";
    
    $test4=query::query4("FaceBook");
    echo "<br>";
    
    $test5=query::query4("GE");
    echo "<br>";
    
    $test6=query::query4("Google");
    echo "<br>";
    
    $test7=query::query4("Mcirosoft");
    echo "<br>";
    
    $test8=query::query4("SIRI");
    echo "<br>";
    
    $test9=query::query4("Sprint");
    echo "<br>";
    
    $test10=query::query4("Yahoo");
    echo "<br>";
      echo "<br>";
    ?>
  </div>


  <div id="footer"><!-- Footer -->
    <p>Copyright &copy; <b>Stock Forecasting</b> | Chaoran Fu, Kai Kang, Yu Sun, Yue Wu, Wuyang Zhang | 2015 </p>
  </div><!-- End Footer -->
</div><!-- End Wrapper -->


</body>
</html>

