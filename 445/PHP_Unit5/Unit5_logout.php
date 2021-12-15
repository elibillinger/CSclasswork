<?php
session_start();
session_unset();
session_destroy();
header("Location: Unit5_index.php");
?>