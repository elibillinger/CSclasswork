<?php
include 'Unit4_database.php';

function console_log($data){
    echo '<script>';
    echo 'console.log('.json_encode($data).')';
    echo '</script>';
}

$conn = getConnection();
$name = $_REQUEST["q"];
$image = $_REQUEST["image"];
$quantity = $_REQUEST["quantity"];
$price = $_REQUEST["price"];
$inactive = $_REQUEST["inactive"];
if($inactive == "true"){
    $inactive = 1;
} else {
    $inactive = 0;
}
$result = addProduct($conn,$name,$image,$quantity,$price,$inactive);
createProductTable();


?>