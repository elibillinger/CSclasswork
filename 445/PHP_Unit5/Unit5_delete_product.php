<?php
include 'Unit5_database.php';

function console_log($data){
    echo '<script>';
    echo 'console.log('.json_encode($data).')';
    echo '</script>';
}

$conn = getConnection();
$name = $_REQUEST["q"];
$value = getProductID($conn,$name);
$id = $value->fetch_assoc();
deleteProduct($conn,$id['id']);
createProductTable();
?>