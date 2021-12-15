<!DOCTYPE html>
<?php
include 'Unit5_database.php';
$conn = getConnection();
$data = getProducts($conn);
?>
<html>
<style>
    <?php include 'Unit5_adminProduct.css'; ?>
</style>
<script src="https://ajax.googleapis.com/ajax/libs/jquery/1.10.1/jquery.min.js"></script>
<body>
<?php 
if(session_status() <> PHP_SESSION_ACTIVE) session_start();
if(isset($_SESSION['role'])){
        if($_SESSION['role'] !== 2){
            header("Location: Unit5_index.php?err=Ypu are not authorized for that page!");
        }
} else {
    header("Location: Unit5_index.php?err=Must Log in first");
}?>
<?php include 'Unit5_header.php';
date_default_timezone_set("America/Denver");
?>
<div id="main" >
<div id="product">
    <h3>Products</h3>
    <div id="productTable"><?php createProductTable()?></div>
</div>
<div id="partform">
    <p id="validation"></p>
<form id="form" action="Unit4_process_order.php" method="post">
    
    <h2>Part Info</h2>
    <label for="pname">Part Name:<span style="color: red"> *</span></label>
    <input type="text" id="pname" name="fname" pattern="[A-Za-z\s']+" title="Names can only include letters,spaces,and apostrophe" required><br><br>
    <label for="pimage">Part Image:<span style="color: red"> *</span></label>
    <input type="text" id="pimage" name="lname" pattern="[A-Za-z\s']+" title="Names can only include letters,spaces,and apostrophe" required><br><br>
    <label for="quantity">Quantity:</label>
    <input type="number" id="quantity" name="quantity" min="1" max="100" ><br><br>
    <label for="price">Price:<span style="color: red"> *</span></label>
    <input type="number" id="price" name="price" min="0" max="1000" required><br><br>
    <input type="checkbox" id="inactive" name="inactive">
    <label for="inactive">Make Inactive</label><br>
    <p id="temp" hidden></p>
</form>
<button onclick="createPart()" id="addPart">Add Part</button>
<button onclick="updatePart()" id="updatePart">Update Part</button>
<button onclick="checkForOrder()" id="deletePart">Delete</button>
</div>
</div>
<?php include 'Unit5_footer.php';?>
<script>
    function checkForm(){
        var pname = $('#pname').val();
        var pimage = $('#pimage').val();
        var price = $('#price').val();
        if(pname == ''){
            $('#validation').html("Please Enter a Part Name");
            $('#pname').focus();
            return false;
        }else if(pimage == ''){
            $('#validation').html("Please Enter a Image name");
            $('#pimage').focus();
            return false;
        }else if(price == ''){
            $('#validation').html("Please Enter a Price");
            $('#price').focus();
            return false;
        } else {
            $('#validation').html(" ");
            return true;
        }
    }
    function createPart(){
        if(checkForm()){
            const xhttp = new XMLHttpRequest();
            var pname = $('#pname').val();
            var pimage = $('#pimage').val();
            var quantity = $('#quantity').val();
            var price = $('#price').val();
            const inactive = document.getElementById('inactive');
            xhttp.onload = function() {
                $("#productTable").html(this.responseText);
                document.getElementById("form").reset();
                getDataFromTable();
            }
            xhttp.open("POST", "Unit5_create.php?q="+pname+"&image="+pimage+"&quantity="+quantity+"&price="+price+"&inactive="+inactive.checked);
            xhttp.send(); 
        }
    }
    function updatePart(){
        if(checkForm()){
        const xhttp = new XMLHttpRequest();
        var pname = $('#pname').val();
        var pimage = $('#pimage').val();
        var quantity = $('#quantity').val();
        var price = $('#price').val();
        const inactive = document.getElementById('inactive');
        var oldname = $('#temp').html();
        xhttp.onload = function() {
            $("#productTable").html(this.responseText);
            document.getElementById("form").reset();
            getDataFromTable();
        }
        xhttp.open("POST", "Unit5_update_product.php?q="+pname+"&image="+pimage+"&quantity="+quantity+"&price="+price+"&inactive="+inactive.checked+"&oldname="+oldname);
        xhttp.send(); 
    }
    }

    function deletePart(){
        if(window.confirm("Are you sure you want to delete this product?")){
            const xhttp = new XMLHttpRequest();
            var pname = $('#pname').val();
            xhttp.onload = function() {
                $("#productTable").html(this.responseText);
                document.getElementById("form").reset();
                getDataFromTable();
            }
            xhttp.open("POST", "Unit5_delete_product.php?q="+pname);
            xhttp.send(); 
        }
    }

    function checkForOrder(){
        if(checkForm()){
        const xhttp = new XMLHttpRequest();
        var pname = $('#pname').val();
        xhttp.onload = function() {
            if(this.responseText == "true"){
                alert("Product cannot be deleted there are exisiting orders of this product");
            } else {
                deletePart();
            }
        }
        xhttp.open("POST", "Unit5_check_order.php?q="+pname);
        xhttp.send(); 
    }
    }
    function getDataFromTable(){
        var table = document.getElementById('productTable');
        var cells = table.getElementsByTagName('td');
        for (var i = 0; i < cells.length; i++){
            var cell = cells[i];
            cell.onclick = function () {
                var rowID = this.parentNode.rowIndex;
                var rowsNotSelected = table.getElementsByTagName('tr');
                for(var row = 0; row < rowsNotSelected.length; row++){
                    rowsNotSelected[row].style.backgroundColor = "";
                    rowsNotSelected[row].classList.remove('selected');
                }
                var rowSelected = table.getElementsByTagName('tr')[rowID];
                rowSelected.style.backgroundColor = "yellow";
                rowSelected.className += " selected";

                $("#pname").val(rowSelected.cells[0].innerHTML);
                $("#pimage").val(rowSelected.cells[1].innerHTML);
                $("#quantity").val(rowSelected.cells[2].innerHTML);
                $("#price").val(rowSelected.cells[3].innerHTML);
                $("#temp").html(rowSelected.cells[0].innerHTML);
                var inactive = rowSelected.cells[4].innerHTML;
                if(inactive == " Yes "){
                    $("#inactive").prop("checked",true);
                } else {
                    $("#inactive").prop("checked",false);
                }
            }
        }
    }

    getDataFromTable();
</script>
</body>
</html>