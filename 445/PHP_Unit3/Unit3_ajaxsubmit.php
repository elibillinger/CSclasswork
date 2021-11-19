<?php
include 'Unit3_database.php';
$conn = getConnection();
$first_name = $_POST['fname'];
$last_name = $_POST['lname'];
$email = $_POST['email'];
$product = $_POST['part'];
$quantity = $_POST['quantity'];
$available = $_POST['available'];
$timestamp = $_POST['timestamp'];


$order = processOrder($conn,$first_name,$last_name,$email,$quantity,$product,$timestamp,$available);
echo $order;



function processOrder($conn,$first_name,$last_name,$email,$quantity,$product,$timestamp,$available){
    if($quantity > $available){
       return "Order refused! Requested quantity " .$quantity." exceeds available " .$available;
    } else {
        $customer = findCustomer($conn,$email);
        if(!$customer){
            insertCustomer($conn,$email,$first_name,$last_name);
        }
        $customerID = getcustomerID($conn,$email)->fetch_assoc();
        $price = getPrice($conn, $product)->fetch_assoc();
        $tax = round($price['price']*$quantity*0.008,2);
        $total = round($price['price']*$quantity*1.008,2);
        addOrder($conn,$customerID['id'],$price['id'],$quantity,$price['price'],$tax,0,$timestamp);
        updateQuantity($conn,$price['id'],$price['in_stock']-$quantity);
        return "Order submitted for: ".$first_name. " " . $last_name . " " . $quantity . " " .$product . " Total: $" .$total;
    }
}

?>