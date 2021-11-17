<!DOCTYPE html>
<html>
    <?php
    include 'Unit2_database.php';
    $conn = getConnection();
    $data = getProducts($conn);
    $customer = getCustomers($conn); 
    $order = getOrders($conn);
    ?>
    <style>
    <?php include 'Unit2_admin.css'; ?>
</style>
<body>
<?php include 'Unit2_header.php';?>
<div>
<h3>Customers</h3>
    <table>
        <tr> 
            <th>Last Name</th>
            <th>First Name</th>
            <th>Email</th>
        </tr>
        <?php if ($customer): ?>
            <?php foreach($customer as $row): ?>
                <?php
                    echo "<tr>";
                    echo "<td>".$row['last_name']."</td>";
                    echo "<td>".$row['first_name']."</td>";
                    echo "<td>".$row['email']."</td>";
                    echo "</tr>";
                    ?>
            <?php endforeach ?>
        <?php endif ?>
    </table>
    <h3>Orders</h3>
    <table>
        <tr> 
            <th>Customer</th>
            <th>Part</th>
            <th>Date</th>
            <th>Quantity</th>
            <th>Price</th>
            <th>Tax</th>
            <th>Donation</th>
            <th>Total</th>
        </tr>
        <?php if ($order): ?>
            <?php foreach($order as $row): ?>
                <?php
                    echo "<tr>";
                    $name = getCustomerName($conn,$row['customer_id'])->fetch_assoc();
                    echo "<td>".$name['last_name']." ".$name['first_name']."</td>";
                    $product = getProductName($conn,$row['product_id'])->fetch_assoc();
                    echo "<td>".$product['product_name']."</td>";
                    echo "<td>".$row['timestamp']."</td>";
                    echo "<td>".$row['quantity']."</td>";
                    echo "<td>".$row['price']."</td>";
                    echo "<td>".$row['tax']."</td>";
                    echo "<td>".$row['donation']."</td>";
                    $total = $row['donation']+$row['tax']+$row['price'];
                    echo "<td>".$total."</td>";
                    echo "</tr>";
                    ?>
            <?php endforeach ?>
        <?php endif ?>
    </table>
    <h3>Products</h3>
    <table>
        <tr> 
            <th>Part</th>
            <th>Quantity</th>
            <th>Price</th>
        </tr>
        <?php if ($data): ?>
            <?php foreach($data as $row): ?>
                <?php
                    echo "<tr>";
                    echo "<td>".$row['product_name']."</td>";
                    echo "<td>".$row['in_stock']."</td>";
                    echo "<td>".$row['price']."</td>";
                    echo "</tr>";
                    ?>
            <?php endforeach ?>
        <?php endif ?>
    </table>
</div>
<?php include 'Unit2_footer.php';?>
</body>
</html>