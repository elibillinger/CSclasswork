<!DOCTYPE html>
<html>
    <style>
        <?php include 'Unit5_common.css'; ?>
    </style>
<body>
    <?php 
    if(session_status() <> PHP_SESSION_ACTIVE) session_start();
    if(isset($_SESSION['role'])){
        if($_SESSION['role'] === 1 ){
            echo "<nav class = 'nav'>";
            echo "<a href='Unit5_index.php'>Home</a>";
            echo "<a href='Unit5_order_entry.php'>Order Entry</a>";
            echo "<a href='Unit5_admin.php'>Admin</a>";
            echo "<a href='Unit5_logout.php' id='admin'>Logout</a>";
            echo "</nav>";
            echo "<header>";
            echo "<p id='welcome'> Welcome, ".$_SESSION['fname']." </p>";
            
        } else if ($_SESSION['role'] === 2){
            echo "<nav class = 'nav'>";
            echo "<a href='Unit5_index.php'>Home</a>";
            echo "<a href='Unit5_store.php'>Store</a>";
            echo "<a href='Unit5_order_entry.php'>Order Entry</a>";
            echo "<a href='Unit5_adminProduct.php'>Products</a>";
            echo "<a href='Unit5_admin.php'>Admin</a>";
            echo "<a href='Unit5_logout.php' id='admin'>Logout</a>";
            echo "</nav>";
            echo "<header>";
            echo "<p id='welcome'> Welcome, ".$_SESSION['fname']." </p>";
        } else {
            echo "<nav class = 'nav'>";
            echo "<a href='Unit5_index.php'>Home</a>";
            echo "<a href='Unit5_store.php'>Store</a>";
            echo "</nav>";
            echo "<header>";
        }
    } else {
        echo "<nav class = 'nav'>";
        echo "<a href='Unit5_index.php'>Home</a>";
        echo "<a href='Unit5_store.php'>Store</a>";
        echo "</nav>";
        echo "<header>";
    }
    
    ?>
    <h1>Computer Parts Store<h1>
</header>
</body>
</html>