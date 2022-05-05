function setup() {
    // Your web app's Firebase configuration
    // const firebaseConfig = {
    const config = {
        apiKey: "AIzaSyB-Q8DgQ34xPRh6aGyHm8uV2kya9b0PhP4",
        authDomain: "arduino-serverless.firebaseapp.com",
        databaseURL: "https://arduino-serverless-default-rtdb.firebaseio.com",
        projectId: "arduino-serverless",
        storageBucket: "arduino-serverless.appspot.com",
        messagingSenderId: "648015857132",
        appId: "1:648015857132:web:8ea3d5cb295be3a8f2acc9"
    };
  
    // Initialize Firebase
    // const app = initializeApp(firebaseConfig);
    firebase.initializeApp(config);
    // var db = app.database();
    var db = firebase.database();

    var bigsound = db.ref('FirebaseDB');
    bigsound.on("value", gotData, errData);
}

function gotData(data) {
    var result = data.val();
    var sensBigs = result.bigsound;
    console.log('Result from Firebase::', sensBigs);

    var tBody = document.getElementById('dataTable').lastElementChild;
    var trl = document.createElement('tr');
    tBody.appendChild(trl);

    var bigsound = document.createElement('td');
    bigsound.innerText = sensBigs;
    trl.appendChild(bigsound);
}
function errData(data) {
    console.log('Error!');
    console.log(data);
}