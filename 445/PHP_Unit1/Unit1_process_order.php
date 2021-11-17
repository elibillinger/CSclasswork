<!DOCTYPE html>
<html>
<body>
<?php include 'Unit1_header.php';?>
Thank you for your order, <?php echo $_POST["fname"]; ?> <?php echo $_POST["lname"]; ?> (<?php echo $_POST["email"]; ?>)<br>
You have selected <?php echo $_POST["quantity"]; ?> <?php echo $_POST["part"]; ?> @ <?php 
if($_POST["part"] == "cpu"){
    echo "$99.99";
} elseif ($_POST["part"] == "gpu"){
    echo "$299.99";
} else {
    echo "$49.99";
}?> <br>
Subtotal: $<?php 
if($_POST["part"] == "cpu"){
    echo 99.99*$_POST["quantity"];
} elseif ($_POST["part"] == "gpu"){ 
    echo 299.99*$_POST["quantity"];
} else {echo 49.99*$_POST["quantity"];
}?> <br>
Total including tax (0.8%): $<?php 
if($_POST["part"] == "cpu"){
    echo round(99.99*$_POST["quantity"]*1.008,2);
} elseif ($_POST["part"] == "gpu"){ 
    echo round(299.99*$_POST["quantity"]*1.008,2);
} else {
    echo round(49.99*$_POST["quantity"]*1.008,2);
}?> <br>
<?php if($_POST["donate"] == "Yes"){
    echo "Total with Donation: $";
    if($_POST["part"] == "cpu"){
        echo ceil(99.99*$_POST["quantity"]*1.008);
    } elseif ($_POST["part"] == "gpu"){ 
        echo ceil(299.99*$_POST["quantity"]*1.008);
    } else {
        echo ceil(49.99*$_POST["quantity"]*1.008);
    }
}
?>
<?php include 'Unit1_footer.php';?>
</body>
</html>