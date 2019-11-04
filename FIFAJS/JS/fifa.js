$('#btTeamNo').click(function(){
var TeamNo1 =$('#noTeam1').val();
var TeamNo2 =$('#noTeam2').val();

$('#TotalTeamNo').val(parseInt(TeamNo1)+parseInt(TeamNo2));

});

function createTable() {

    // get the reference for the body
   var DvTable = document.getElementById('Table');

    // creates a <table> element and a <tbody> element
  var tbl = document.createElement("table");
  var tblBody = document.createElement("tbody");
  
  }