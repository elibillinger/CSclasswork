<!DOCTYPE html>
<?php
include 'Unit4_database.php';
$conn = getConnection();
$data = getProducts($conn);
?>
<html>
<style>
    <?php include 'Unit4_order_entry.css'; ?>
</style>
<script src="https://ajax.googleapis.com/ajax/libs/jquery/1.10.1/jquery.min.js"></script>
<body>
<?php include 'Unit4_header.php';
date_default_timezone_set("America/Denver");
?>
<div id="main" >
<form id="form" action="Unit4_process_order.php" method="post">
    <div id="personal">
    <h2>Personal Info</h2>
    <label for="fname" >First Name:<span style="color: red"> *</span></label>
    <input type="text" id="fname" name="fname" pattern="[A-Za-z\s']+" title="Names can only include letters,spaces,and apostrophe" onkeyup="showCustomerTable(this.value,'first')" required><br><br>
    <label for="lname" >Last Name:<span style="color: red"> *</span></label>
    <input type="text" id="lname" name="lname" pattern="[A-Za-z\s']+" title="Names can only include letters,spaces,and apostrophe" onkeyup="showCustomerTable(this.value,'last')" required><br><br>
    <label for="email">Email:<span style="color: red"> *</span></label>
    <input type="email" id="email" name="email" required><br>
    </div>
    <div id="productInfo">
    <h2>Product Info</h2>
    <select name="part" id = "part"required onchange=showAvailable(this.value)>
        <option value="" disabled selected hidden> Select a Part</option>
        <?php if ($data): ?>
            <?php foreach($data as $row): ?>
                <option value=<?= $row['product_name'] ?> data-image="<?= $row['image_name'] ?>"data-qty="<?= $row['in_stock'] ?>"><?= $row['product_name'] ?> $<?= $row['price'] ?></option>
            <?php endforeach ?>
        <?php endif ?>
    </select> <br>
    <label for="available">Available:</label>
    <input type="text" id="available" name="available" value="" readonly><br>
    <label for="quantity">Quantity:</label>
    <input type="number" id="quantity" name="quantity" value="1" min="1" max="100" required><br>
    </div>
    <input type="hidden" name="timestamp" value="<?php echo time(); ?>">
    <input type="button" id="submit" value="Purchase">
    <input type="reset" value="Clear Fields">
</form>
<div id="product">
    <p id="temp">Choose an exisiting customer:</p><br>
    <div id="customers"></div>
</div>
</div>
<?php include 'Unit4_footer.php';?>
<script src="Unit4_script.js"></script>
</body>
</html>