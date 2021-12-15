<!DOCTYPE html>
<?php
include 'Unit5_database.php';
$conn = getConnection();
$data = getProducts($conn);
?>
<html>
<style>
    <?php include 'Unit5_index.css'; ?>
</style>
<body>
<?php include 'Unit5_header.php';?>
<div id="main" >
<div id="loginform">
    <p>Welcome! Please login or select Continue as Guest to begin</p>
    <p id="validation"><?php if(isset($_GET['err'])){echo $_GET['err'];}?></p>
<form id="form" action="Unit5_login.php" method="post">
    <label for="email">Email<span style="color: red"> *</span></label><br>
    <input type="email" id="email" name="email" required><br><br>
    <label for="password">Password<span style="color: red"> *</span></label><br>
    <input type="password" id="password" name="password" required><br><br>
    <input type="submit" value="Login"><br>
    <input type="checkbox" id="remember" name="remember">
    <label for="remember">Remember me</label>
    <p id="forgot">Forgot <span style="color : blue"> password?</span></p>
</form>
<a id="link" href="Unit5_store.php"><button id="guest">Continue as Guest</button></a>
</div>
</div>
<?php include 'Unit5_footer.php';?>
</body>
</html>