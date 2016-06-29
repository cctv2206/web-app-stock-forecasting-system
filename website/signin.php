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
  
    <?php
    $stockNamesArr = array("Amazon", "Apple", "BAC", "FaceBook", "GE", "Google", "Microsoft", "SIRI", "Sprint", "Yahoo");
    $skip = false;
    $continue = false;

      if ($_SESSION['userName'] and $_SESSION['password']) // check if this is the same session
      {
        $uname = $_SESSION['userName'];
        $pass = $_SESSION['password'];
        $skip = true;
        $stockArray = $_SESSION['array'];
        $stockNumber = $_SESSION['number'];
        $continue = true;
        //print_r($stockArray);
        
      }
      else // this is the new session
      {
        $uname = $_POST['name'];
        $pass = $_POST['pwd'];
      }

        $sql = "SELECT count(*) FROM users WHERE(name='$uname' and  password='$pass')";

        $qury = mysql_query($sql);
        $result = mysql_fetch_array($qury);

        $sql1 = "SELECT * FROM users WHERE(name='$uname' and  password='$pass')";
        $qury1 = mysql_query($sql1);
        $result1 = mysql_fetch_array($qury1);

      


      if($result[0]>0 or $continue)  // -------------------------------------- log in success
      {
          $_SESSION['userName'] = $uname;
          $_SESSION['password'] = $pass;
          $_SESSION['stocks'] = $result1['stocks'];
          $_SESSION['number'] = $result1['number'];
          $stockNumber = $_SESSION['number'];
          $stockNames = $_SESSION['stocks'];
          $stockArray = explode(',', $stockNames);

          echo 
            "<div id='tryThis' style='height: 37px'>
            <ul id='nav-home'> <!-- Navigation -->
              <li><a href='index.html'>Home</a></li>
              <li><a href='signin.php'>My Stocks</a></li>
              <li><a href='logout.php'>Log Out</a></li>
            </ul>
          </div>
          <br>
          <br>
          <br>
          <div id='hahaha' class='column' style='background-color:#f2f2f2; height:400px; width:71%'>";
          // the div starts here

          echo "Welcome ".$_SESSION['userName']."!";
          echo "<br>";
        

        if ($_SESSION['number'] == 0)  // ------------------------ No Stocks
        {
          echo "You haven't selected any stocks.";
          echo "<br>";
          echo "You can add some stocks on the right.";
          echo "<br>";
        }
        else // ------------------------------------------------- have some stock
        {
          echo "<table id='t01' style='width:100%'>"; // ------- the stock table start
          echo "<caption>Your Stocks & Predictions</caption>";
          echo "<tr>";
          echo "<th >Stock</th>";
          echo "<th >Price</th>";
          echo "<th >Minute</th>";
          echo "<th >NextDay</th>";
          echo "<th >NextWeek</th>";
          echo "<th >NextMonth</th>";
          echo "<th >History</th>";
          echo "</tr>";
    
          for ($i = 0; $i < $stockNumber; $i++)
          {
            $query = "
            SELECT *
            FROM CurrentPrice
            WHERE Stocks = '".nameToStock($stockArray[$i])."' 
            ORDER BY ID ASC";
            $result = mysql_query( $query );
            $row = mysql_fetch_assoc( $result );

            $query1 = "
            SELECT *
            FROM Predict
            WHERE Stocks = '".nameToStock($stockArray[$i])."' 
            ORDER BY ID ASC";
            $result1 = mysql_query( $query1 );

            $row1 = mysql_fetch_assoc( $result1 );
            $Minute = $row1['Minute'];
            $row1 = mysql_fetch_assoc( $result1 );
            $NextDay = $row1['NextDay'];
            $row1 = mysql_fetch_assoc( $result1 );
            $NextWeek = $row1['NextWeek'];
            $row1 = mysql_fetch_assoc( $result1 );
            $NextMonth = $row1['NextMonth'];

            echo "<tr>";
            echo "<td> <a href='".$stockArray[$i].".html'>".$stockArray[$i]."</a></td>";//Stock name current price chart
            echo "<td> $".$row['Price']."</td>";//price
            echo "<td> $".$Minute."</td>";//Minute
            echo "<td> $".$NextDay."</td>";//next day
            echo "<td> $".$NextWeek."</td>";//next week
            echo "<td> $".$NextMonth."</td>";//next month
            echo "<td> <a href='".$stockArray[$i]."History.html'>"."view"."</a></td>"; // History
            echo "</tr>";
          }
          echo "</table>"; // ------------------------------- the stock table ends

        }
        echo "</div>";

        // ------------------------------- Add stocks
        echo "<div class='column' id='hehehe' style='background-color:#ffffff; height:350px; width:20.9%'>";
        echo "Stocks Selection";
        echo "<br>";
        echo "<br>";
        echo "<form action='addSubmit.php' method='POST'>";  // ----------------- check box 
        $arrlength = count($stockNamesArr);
        for ($i = 0; $i < $arrlength; $i++)
        {
          if(in_array($stockNamesArr[$i], $stockArray))
          {
            echo "<input type='checkbox' name='".$stockNamesArr[$i]."' checked='checked'/>".$stockNamesArr[$i]."<br />";
          }
          else
          {
            echo "<input type='checkbox' name='".$stockNamesArr[$i]."' />".$stockNamesArr[$i]."<br />";
          }
        }

        echo "<input type='submit' value='Submit'>";
        echo "</form>";

        $stockArray = array();
        $stockNumber = 0;

        $_SESSION['stocks'] = "";
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
        //$sql = "UPDATE users SET stocks = '$stocks' , number = '$stockNumber' WHERE(name='$uname' and  password='$pass')";
        $_SESSION['array'] = $stockArray;
        $_SESSION['number'] = $stockNumber;
        echo "</div>";



      }
      else  // -------------------------------------------------- log in failed
      {
        echo 
            "<div id='tryThis' style='height: 37px'>
            <ul id='nav-home'> <!-- Navigation -->
              <li><a href='index.html'>Home</a></li>
              <li><a href='login.html'>Log In</a></li>
            </ul>
          </div>
          <br>
          <br>
          <br>
          <div id='hahaha' class='column' style='background-color:#f2f2f2; height:350px; width:96%'>";
        echo "Login Failed";
        echo "<br>";
        echo "Please try again.";
        echo "</div>";//div ends here
      }
      
    ?>

<br>

  <div id="footer"><!-- Footer -->
    <p>Copyright &copy; <b>Stock Forecasting</b> | Chaoran Fu, Kai Kang, Yu Sun, Yue Wu, Wuyang Zhang | 2015 </p>
  </div><!-- End Footer -->
</div><!-- End Wrapper -->


</body>
</html>

<?php
function nameToStock($name)
{
  $stock = "";
  switch ($name)
  {
    case "Amazon":
      $stock = "AMZN";
      break;
    case "Apple":
      $stock = "AAPL";
      break;
    case "BAC":
      $stock = "BAC";
      break;
    case "FaceBook":
      $stock = "FB";
      break;
    case "GE":
      $stock = "GE";
      break;
    case "Google":
      $stock = "GOOG";
      break;
    case "Microsoft":
      $stock = "MSFT";
      break;
    case "SIRI":
      $stock = "SIRI";
      break;
    case "Sprint":
      $stock = "S";
      break;
    case "Yahoo":
      $stock = "YHOO";
      break;
    default:
      $stock = "YHOO";
      break;

  }
  return $stock;
}

?>
