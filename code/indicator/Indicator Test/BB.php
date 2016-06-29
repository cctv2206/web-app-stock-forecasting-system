<?PHP
    require_once('Indicator.php');
    $test=Indicator::BB("Facebook");
    //echo $test;
    for ($i=0;$i<20;$i++){
        echo $test[$i];
        echo "<br>";
    }
    ?>