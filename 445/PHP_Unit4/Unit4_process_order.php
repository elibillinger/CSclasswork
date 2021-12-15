<!DOCTYPE html>
<html>
<body>
<?php include 'Unit4_header.php';?>
<div>
<?php
include 'Unit4_database.php';
$email = $_POST["email"];
$first_name = $_POST["fname"];
$last_name = $_POST["lname"];
$product = $_POST["part"];
$quantity = $_POST["quantity"];
$timestamp = $_POST['timestamp'];
$price = getPrice($conn, $product);
$customer = findCustomer($conn,$email);
if ($customer){
    echo "<p><strong>Hello, $first_name $last_name - </strong><em>Welcome back!</em></p>";
    echo "<p>We hope you enjoy your new $product!</p>";
    echo "<p>Order details:</p>";
} else {
    echo "<p><strong>Hello, $first_name $last_name - </strong><em>Congrats on your first order!</em></p>";\
    insertCustomer($conn,$email,$first_name,$last_name);
    echo "<p>We hope you enjoy your new $product!</p>";
    echo "<p>Order details:</p>";
}
?>
<?php
 echo "<p>   $quantity @ $";
while ($row = $price->fetch_assoc()) {
    echo $row['price'].":&nbsp&nbsp&nbsp$".$row['price'];
    echo "<p> &nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp Tax: &nbsp&nbsp&nbsp&nbsp$";
    $tax = round($row['price']*$_POST["quantity"]*0.008,2);
    echo "$tax </p>";
    echo "<p> &nbsp&nbsp&nbsp&nbsp&nbsp Subtotal: &nbsp&nbsp&nbsp&nbsp$";
    echo round($row['price']*$_POST["quantity"]*1.008,2)."</p>";
    $donation = 0;
    if($_POST["donate"] == "Yes"){
        echo "<p> Total with donation: &nbsp&nbsp&nbsp&nbsp$";
        $donation = ceil($row['price']*$_POST["quantity"]*1.008) - round($row['price']*$_POST["quantity"]*1.008,2);
        echo ceil($row['price']*$_POST["quantity"]*1.008)."</p>";
    } else {
        echo "<p> &nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp Total: &nbsp&nbsp&nbsp&nbsp&nbsp$";
        echo round($row['price']*$_POST["quantity"]*1.008,2)."</p>";
    }
    $cusID = getcustomerID($conn,$email);
    $customerID = $cusID->fetch_assoc();
    $orderAdded = addOrder($conn,$customerID['id'],$row['id'],$quantity,$row['price'],$tax,$donation,$timestamp);
    if($orderAdded){
        updateQuantity($conn,$row['id'],$row['in_stock']-$quantity);
    }
}
?>
</div>
<div>
    <p id= "customer"></p>
    <p id="intro"></p>
    <p id = "order"></p>
</div>
<?php include 'Unit4_footer.php';?>
</body>
</html>