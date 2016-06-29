<?php 
  include_once("db.php"); 
  session_start();
?>

<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" lang="en">

<head>
  <meta http-equiv="Content-Type" content="text/html; charset=utf-8"/> 
  
  <title> Stock Forecasting - Home</title>
  
  <link rel="stylesheet" type="text/css" href="css/style.css" />
  <script type="text/javascript" src="js/jquery.js"></script>
  <script type="text/javascript" src="js/apple.js"></script>
  
  
  <script type="text/javascript">
  function equalHeight(group) {
    tallest = 0;
    group.each(function() {
      thisHeight = $(this).height();
      if(thisHeight > tallest) {
        tallest = thisHeight;
      }
    });
    group.height(tallest);
  }
  $(document).ready(function() {
    equalHeight($(".column"));
  });
  </script>
</head>


<body>
<div id="wrapper">

  <div id="header"><!-- Start Header -->
    <span id="number">Stock Forecasting </span>
  </div><!-- End Header -->
  
  <div id="tryThis" style="height: 37px">
    <ul id="nav-home"> <!-- Navigation -->
      <li><a href="index.html">Home</a></li>
      <li><a href="signin.php">My Stocks</a></li>
      <li><a href="logout.php">Log Out</a></li>
    </ul>
  </div>
  <br>
  <br>
  <br>
  <div id='hahaha' class="column" style="background-color:#f2f2f2; height:350px; width:96%">

    <?php
    $stockNamesArr = array("Amazon", "Apple", "BAC", "FaceBook", "GE", "Google", "Microsoft", "SIRI", "Sprint", "Yahoo");

    $skip = false;
    $continue = false;

        echo "    Added Stocks Successfully!";
        $uname = $_SESSION['userName'];
        $pass = $_SESSION['password'];
        $skip = true;
        $stockArray = $_SESSION['array'];
        $stockNumber = $_SESSION['number'];
        $continue = true;
        
        $sql = "SELECT count(*) FROM users WHERE(name='$uname' and  password='$pass')";

        $qury = mysql_query($sql);
        $result = mysql_fetch_array($qury);

        $sql1 = "SELECT * FROM users WHERE(name='$uname' and  password='$pass')";
        $qury1 = mysql_query($sql1);
        $result1 = mysql_fetch_array($qury1);


          $_SESSION['userName'] = $uname;
          $_SESSION['password'] = $pass;
          $_SESSION['stocks'] = $result1['stocks'];
          $_SESSION['number'] = $result1['number'];
          $stockNumber = $_SESSION['number'];
          $stockNames = $_SESSION['stocks'];
          $stockArray = explode(',', $stockNames);

          echo "<br>";
          echo "Click here to return.";
          echo "<form action='signin.php'>";
          echo "<input type='submit' value='Return'>";
          echo "</form>";
    ?>
<br>

<?php

$stockArray = array();
$stockNumber = 0;
$_SESSION['stocks'] = "";
$arrlength = count($stockNamesArr);
for ($i = 0; $i < $arrlength; $i++)
{
  if (isset($_POST[$stockNamesArr[$i]]))
  {
    $_SESSION['stocks'] .= $stockNamesArr[$i].",";
    array_push($stockArray, $stockNamesArr[$i]);
    $stockNumber += 1;
  }
}

$stocks = $_SESSION['stocks'];
$sql = "UPDATE users SET stocks = '$stocks' , number = '$stockNumber' WHERE(name='$uname' and  password='$pass')";
$qury = mysql_query($sql);
$_SESSION['array'] = $stockArray;
$_SESSION['number'] = $stockNumber;

?>

  </div>
  <div id="footer"><!-- Footer -->
    <p>Copyright &copy; <b>Stock Forecasting</b> | Chaoran Fu, Kai Kang, Yu Sun, Yue Wu, Wuyang Zhang | 2015 </p>
  </div><!-- End Footer -->
</div><!-- End Wrapper -->


</body>
</html>

