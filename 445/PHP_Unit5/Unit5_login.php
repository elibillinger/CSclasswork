<?php
include 'Unit5_database.php';
session_start();
if(empty($_POST['email'])){
    header("Location: Unit5_index.php?err=Invalid User");
}
if(empty($_POST['password'])){
    header("Location: Unit5_index.php?err=Invalid User");
}
$conn = getConnection();
$email = $_POST["email"];
$password = $_POST["password"];
$check = checkUser($conn,$email,$password);
$user = getUser($conn,$email,$password);
if($check){
    $u = $user->fetch_assoc();
    $_SESSION["role"] = $u['role'];
    $_SESSION["fname"] = $u['first_name'];
    if($_SESSION["role"] == 1){
        header("Location: Unit5_order_entry.php");
    } else if( $_SESSION["role"] == 2){
        header("Location: Unit5_adminProduct.php");
    }
} else {
    header("Location: Unit5_index.php?err=Invalid User");
}
?>