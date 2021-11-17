<!DOCTYPE html>
<?php
include 'Unit2_database.php';
$conn = getConnection();
$data = getProducts($conn);
?>
<html>
<style>
    <?php include 'Unit2_store.css'; ?>
</style>
<script src="https://ajax.googleapis.com/ajax/libs/jquery/1.10.1/jquery.min.js"></script>
<body>
<?php include 'Unit2_header.php';
date_default_timezone_set("America/Denver");
?>
<div id="main" >
<form id="form" action="Unit2_process_order.php" method="post">
    <div id="personal">
    <h2>Personal Info</h2>
    <label for="fname">First Name:<span style="color: red"> *</span></label>
    <input type="text" id="fname" name="fname" pattern="[A-Za-z\s']+" title="Names can only include letters,spaces,and apostrophe" required><br><br>
    <label for="lname">Last Name:<span style="color: red"> *</span></label>
    <input type="text" id="lname" name="lname" pattern="[A-Za-z\s']+" title="Names can only include letters,spaces,and apostrophe" required><br><br>
    <label for="email">Email:<span style="color: red"> *</span></label>
    <input type="email" id="email" name="email" required><br>
    </div>
    <div id="productInfo">
    <h2>Product Info</h2>
    <select name="part" id = "part"required onchange=showImage()>
        <option value="" disabled selected hidden> Select a Part</option>
        <?php if ($data): ?>
            <?php foreach($data as $row): ?>
                <option value=<?= $row['product_name'] ?> data-image="<?= $row['image_name'] ?>"data-qty="<?= $row['in_stock'] ?>"><?= $row['product_name'] ?> $<?= $row['price'] ?></option>
            <?php endforeach ?>
        <?php endif ?>
    </select> <br>
    <label for="quantity">Quantity:</label>
    <input type="number" id="quantity" name="quantity" value="1" min="1" max="100" required><br>
    </div>
    <p>Round up to the nearest dollar for a donation?</p>
    <input type="radio" id="yes" name="donate" value="Yes">
    <label for="yes">Yes</label><br>
    <input type="radio" id="no" name="donate" value="No" checked>
    <label for="no">No</label><br>
    <input type="hidden" name="timestamp" value="<? echo time(); ?>">
    <input type="submit" value="Purchase">
</form>
<div id="product">
    <p id="temp">Image of part will display here on selection</p>
    <img>
    <p id ="message"></p>
</div>
</div>
<?php include 'Unit2_footer.php';?>
<script>
    function showImage(){
        var imgName = $("#part option:selected").attr('data-image');
        var qty = $("#part option:selected").attr('data-qty');
        $("#temp").hide();
        $("img")
            .attr('src', 'images/'+imgName)
            .width('300px')
            .height('300px');
        $("#quantity").attr({
            "max" : qty
        });
        $("#message").css("margin-top","10px");
        if(qty < 10 && qty > 1){
            $("#message").show();
            $("#message").text("Only " + qty + " left!");
        } else if (qty < 1){
            $("#message").show();
            $("#message").text("SOLD OUT");
        } else {
            $("#message").hide();
        }
        
    }
</script>
</body>
</html>