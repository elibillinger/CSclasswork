<?php
$conn = getConnection();
getProducts($conn);
function getConnection() {
    include 'Unit2_database_credentials.php';
    $conn = new mysqli($servername,$username,$password,$dbname);
    if($conn->connect_error) {
        die("Connection failed: " . $conn->connect_error);
    } 
    return $conn;
}
function getProducts($conn){
    $sql = "SELECT * FROM product";
    $result = mysqli_query($conn,$sql);   
    return $result;
}

function findCustomer ($conn, $email){
    $stmt = $conn->prepare("SELECT * FROM customer WHERE email=?");
    $stmt->bind_param("s",$email);
    $stmt->execute();
    $result = $stmt->get_result();
    if($result->num_rows > 0){
        $row = $result->fetch_assoc();
        return true;
    } else {
        return false;
    }
}

function insertCustomer ($conn, $email, $first_name, $last_name){
    $stmt = $conn->prepare("INSERT INTO customer (first_name,last_name,email) VALUES (?,?,?)");
    $stmt->bind_param("sss",$first_name,$last_name,$email);
    $stmt->execute();
}

function getPrice ($conn, $product){
    $stmt = $conn->prepare("SELECT price,id,in_stock FROM product WHERE product_name=?");
    $stmt->bind_param("s",$product);
    $stmt->execute();
    $result = $stmt->get_result();
    return $result;
}
function getcustomerID ($conn, $email){
    $stmt = $conn->prepare("SELECT id FROM customer WHERE email=?");
    $stmt->bind_param("s",$email);
    $stmt->execute();
    $result = $stmt->get_result();
    return $result;
}
function addOrder ($conn,$customerID,$productID,$quantity,$price,$tax,$donation,$timestamp){
    $check = $conn->prepare("SELECT id FROM orders WHERE product_id=? AND customer_id=? AND timestamp=?");
    $check->bind_param("iii",$productID,$customerID,$timestamp);
    $check->execute();
    $result = $check->get_result();
    if($result->num_rows > 0){
        return false;
    } else {
        $stmt = $conn->prepare("INSERT INTO orders (product_id,customer_id,quantity,price,tax,donation,timestamp) VALUES (?,?,?,?,?,?,?)");
        $stmt->bind_param("iiidddi",$productID,$customerID,$quantity,$price,$tax,$donation,$timestamp);
        $stmt->execute();
        return true;
    }
}

function getCustomers($conn){
    $sql = "SELECT * FROM customer";
    $result = mysqli_query($conn,$sql);   
    return $result;
}
function getCustomerName($conn,$customerID){
    $stmt = $conn->prepare("SELECT last_name,first_name FROM customer WHERE id=?");
    $stmt->bind_param("i",$customerID);
    $stmt->execute();
    $result = $stmt->get_result();
    return $result;
}
function getProductName($conn,$productID){
    $stmt = $conn->prepare("SELECT product_name FROM product WHERE id=?");
    $stmt->bind_param("i",$productID);
    $stmt->execute();
    $result = $stmt->get_result();
    return $result;
}

function getOrders($conn){
    $sql = "SELECT * FROM orders";
    $result = mysqli_query($conn,$sql); 
    return $result;
}
function updateQuantity($conn,$productID,$quantity){
    $stmt = $conn->prepare("UPDATE product SET in_stock=? WHERE id=?");
    $stmt->bind_param("ii",$quantity,$productID);
    $stmt->execute();
}
?>