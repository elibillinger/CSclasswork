<?php
include 'Unit4_database.php';

function console_log($data){
    echo '<script>';
    echo 'console.log('.json_encode($data).')';
    echo '</script>';
}

$conn = getConnection();
$name = $_REQUEST["q"];
$value = getProductID($conn,$name);
$id = $value->fetch_assoc();
$result = findOrder($conn,$id['id']);
if($result){
    echo "true";
} else {
    echo "false";
}
?>