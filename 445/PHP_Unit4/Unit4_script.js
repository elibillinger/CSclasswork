function showAvailable(product){
    const xhttp = new XMLHttpRequest();
    xhttp.onload = function() {
        $("#available").val(this.responseText);
    }
    xhttp.open("GET", "Unit4_get_quantity.php?q="+product);
    xhttp.send(); 
}
function showCustomerTable(value,str){
    if(value.length == 0){
        $("#customers").html("");
        return;
    } else {
        const xmlhttp = new XMLHttpRequest();
        xmlhttp.onload = function() {
            $("#customers").html(this.responseText);
            getDataFromTable();
        }
        xmlhttp.open("GET","Unit4_get_customer_table.php?q=" + value + "&partName="+str);
        xmlhttp.send();
    }
}

function getDataFromTable(){
    var table = document.getElementById('customer-table');
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

            $("#fname").val(rowSelected.cells[0].innerHTML);
            $("#lname").val(rowSelected.cells[1].innerHTML);
            $("#email").val(rowSelected.cells[2].innerHTML);
        }
    }
}
$(document).ready(function (){
$("#submit").click(function (e){
    e.preventDefault();
    var fname = $("#fname").val();
    var lname = $("#lname").val();
    var email = $("#email").val();
    var product = $("#part").val();
    if(fname == ''|| lname == '' || email == ''){
        alert("Please Fill All Fields");
        return false;
    }else if(!product){
        alert("Please select a part");
        return false;
    }
    var data = $("form").serialize();
    $.ajax({
        type: "POST",
        url: "Unit4_ajaxsubmit.php",
        data: data,
        cache: false,
        success: function(result){
            if(result.includes("refused!")){
                alert(result);
            } else {
                $("#customers").html("<p>"+result+"</p>");
                document.getElementById("form").reset();
            }
        }
    });
});
});