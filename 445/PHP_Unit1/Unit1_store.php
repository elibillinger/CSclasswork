<!DOCTYPE html>
<html>
<style>
    <?php include 'Unit1_store.css'; ?>
</style>
<script src="https://ajax.googleapis.com/ajax/libs/jquery/1.10.1/jquery.min.js"></script>
<body>
<?php include 'Unit1_header.php';?>
<div id="main" >
<form id="form" action="Unit1_process_order.php" method="post">
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
    <select name="part" required onchange=showImage(this.value)>
        <option value="" disabled selected hidden> Select a Part</option>
        <option value="cpu">CPU $99.99</option>
        <option value="gpu">GPU $299.99</option>
        <option value="motherboard">Motherboard $49.99</option>
    </select> <br>
    <label for="quantity">Quantity:</label>
    <input type="number" id="quantity" name="quantity" value="1" min="1" max="100" required><br>
    </div>
    <p>Round up to the nearest dollar for a donation?</p>
    <input type="radio" id="yes" name="donate" value="Yes">
    <label for="yes">Yes</label><br>
    <input type="radio" id="no" name="donate" value="No" checked>
    <label for="no">No</label><br>
    <input type="submit" value="Purchase">
</form>
<div id="product">
    <p id="temp">Image of part will display here on selection</p>
    <img>
</div>
</div>
<?php include 'Unit1_footer.php';?>
<script>
    function showImage(Image){
        $("#temp").hide()
        $("img")
            .attr('src', 'images/'+Image+'.jpg')
            .width('300px')
            .height('300px');
    }
</script>
</body>
</html>