//written by Yue Wu
//debugged by Yue Wu
<?php
    /*
     * Following code will create a new product row
     * All product details are read from HTTP Post Request
     */
    // array for JSON response
    $response= array();
    // check for required fields
    if(isset(isset($_POST['pricename'])) {
       // $name= $_POST['name'];
        $pricename= $_POST['pricename'];
        //$description= $_POST['description'];
        // include db connect class
        //require_once__DIR__ . '/db_connect.php';
        // connecting to db
        $con = mysqli_connect("localhost", "root", "shmily", "StockForecasting");
        if (!$con)
        {
            die('Could not connect: ' . mysql_error());
        }
        // mysql inserting a new row
        $result= mysqli_query($con, "SELECT Open FROM FaceBook");
        // check if row inserted or not
                              $i=0;
                              if (mysqli_num_rows($result) > 0) {
                              // output data of each row
                              while($row = mysqli_fetch_assoc($result)) {
                              $response[$i]=$row['Open'];
                              $i++;
                              }
                              } else {
                              echo "0 results";
                              }

        if($result) {
            // successfully inserted into database
                       // echoing JSON response
            echojson_encode($response);
        }
                              
    ?>
