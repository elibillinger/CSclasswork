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
$oldname = $_REQUEST["oldname"];
$value = getProductID($conn,$oldname);
$id = $value->fetch_assoc();
if($inactive == "true"){
    $inactive = 1;
} else {
    $inactive = 0;
}
$result = updateProduct($conn,$name,$image,$quantity,$price,$inactive,$id['id']);
createProductTable();


?>