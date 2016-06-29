<?php include_once("db.php"); ?>
 
<?php
       $user = $_POST['n'];
       $pass = $_POST['p'];
       $email = $_POST['email1'];
       #$id = $_POST['id'];
    #$sql = "INSERT into phplogin values(".$id.",'".$user."','".$pass."')";
      $sql = "INSERT into users values('$user','$email','$pass', '', 0)";
       $qury = mysql_query($sql);

    #  INSERT into phplogin values(
    #   1,
    #   'satish',
    #   'satish');

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
      <li><a href="login.html">Log In</a></li>
    </ul>
  </div>
  <br>
  <br>
  <br>
  <div id='hahaha' class="column" style="background-color:#f2f2f2; height:350px; width:96%">

    
<br>

<?php
    if(!$qury)
    {
              echo "Failed ".mysql_error();
    }
    else
    {
              echo "Successful";
    }
?>

  </div>
  <div id="footer"><!-- Footer -->
    <p>Copyright &copy; <b>Stock Forecasting</b> | Chaoran Fu, Kai Kang, Yu Sun, Yue Wu, Wuyang Zhang | 2015 </p>
  </div><!-- End Footer -->
</div><!-- End Wrapper -->


</body>
</html>


