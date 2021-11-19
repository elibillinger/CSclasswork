<?php
include 'Unit3_database.php';
$conn = getConnection();
$q = $_REQUEST["q"];
$name = $_REQUEST["partName"];
$result = getCustomers($conn);
$a = array();
$partOfName = "";
if($name == 'first'){
    $partOfName = "first_name";
} else {
    $partOfName = "last_name";
}
if($q !== ""){
    $q = strtolower($q);
    $len = strlen($q);
    foreach($result as $row) {
        if (stristr($q, substr($row[$partOfName],0,$len))) {
            array_push($a,$row);
        }
    }
}
if(count($a) > 0){
    echo "<br>";
    echo "<table id='customer-table'>";
    echo "<tr>";
    echo "<th>First Name</th>";
    echo "<th>Last Name</th>";
    echo "<th>Email</th>";
    echo "</tr>";
    foreach($a as $row) {
        echo "<tr>";
        echo "<td>".$row['first_name']."</td>";
        echo "<td>".$row['last_name']."</td>";
        echo "<td>".$row['email']."</td>";
        echo "</tr>";
    }
    echo "</table>";
} else {
    echo "<br><p>No Suggestions</p>";
}
?>