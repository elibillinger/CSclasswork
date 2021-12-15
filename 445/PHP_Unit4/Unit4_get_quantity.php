<?php
include 'Unit4_database.php';
$conn = getConnection();
$q = $_REQUEST["q"];
$result = getQuantity($conn,$q);
echo $result;
?>