async function onClickRecoverButton(){
    const password = form.password().value;

    const {data, error} = await supabaseClient.auth.updateUser(password, {
        password: password
    });

    if(error){
        alert(`Erro ao tentar redefinir senha: ${error.message}`);
    } else{
        alert(`Senha redefinida com sucesso!`);
    }
}

document.addEventListener("DOMContentLoaded", async () => {
      const { data, error } = await supabaseClient.auth.getSession();
      if (error || !data.session) {
        alert("Erro: sessão inválida.");
      }
});


function recoverPassword(){
    showLoading();
    firebase.auth().sendPasswordResetEmail(form.email().value).then(() => {
        hideLoading();
        alert('Email de Redefinição Enviado. Verifique seu Email para mais informações');
    }).catch(error =>{
        hideLoading();
        alert(errorMessageLogin(error));
    });
}

function onClickLoginBackButton() {
    showLoading();
    setTimeout(() => {
        window.location.href = "../login/index.html";
    }, 3000);
}

function onClickButton() {
    tooglePasswordErrors();
    toggleSamePassword();
}

document.addEventListener("DOMContentLoaded", function () {
    form.password().addEventListener("input", () => {
        tooglePasswordErrors(); 
        toggleButtonsDisable();
    });

    form.confirmPassword().addEventListener("input", () => {
        toggleSamePassword();
        toggleButtonsDisable();
    })
});

function onChangePassword(){
    tooglePasswordErrors();
    toggleButtonsDisable();
}

function isPasswordValid(){
    const password = form.password().value;

    if(!password){
        return false;
    }
     return true;
    
}

function tooglePasswordErrors () {
    const password = form.password().value;

    form.passwordRequiredError().style.display = password ? "none" : "block";
}

function toggleSamePassword() {
    const confirmPassword = form.confirmPassword().value;
    const password = form.password().value;

    form.passwordDifferentError().style.display = password == confirmPassword ? "none" : "block";
    form.passwordDifferentRequiredError().style.display = confirmPassword ? "none" : "block"; 
}

function toggleButtonsDisable () {
    const email = form.email().value;
    const emailValid = isEmailValid();
    const passwordValid = isPasswordValid(); 

    form.loginButton().disabled = !passwordValid;
}

document.addEventListener("DOMContentLoaded", function () {
    const showpassword = form.showPassword();
    const showpasswordtwo = form.showPasswordTwo();
    const password = form.password();
    const confirmPassword = form.confirmPassword();

   showpassword.addEventListener('click', function () {
        if (password.type === 'password') {
            password.type = 'text';
            showpassword.querySelector('img').src = '../images/lock-open-alt-solid-24.png';
        } else {
            password.type = 'password';
            showpassword.querySelector('img').src = '../images/lock-alt-solid-24.png';
        }
    });

    showpasswordtwo.addEventListener('click', function () {
        if (confirmPassword.type === 'password') {
            confirmPassword.type = 'text';
            showpasswordtwo.querySelector('img').src = '../images/lock-open-alt-solid-24.png'; 
        } else {
            confirmPassword.type = 'password';
            showpasswordtwo.querySelector('img').src = '../images/lock-alt-solid-24.png'; 
        }
    });
});


const form = {
    password: () => document.getElementById('recover-password-input'),
    confirmPassword: () => document.getElementById('recover-confirm-password-input'),
    loginButton: () => document.getElementById('recover-button'),
    showPassword: () => document.getElementById('show-password'),
    showPasswordTwo: () => document.getElementById('show-password-2'),
    passwordDifferentRequiredError: () => document.getElementById('different-password-required-error'),
    passwordDifferentError: () => document.getElementById('different-password-error'),
    passwordInvalidError: () => document.getElementById('password-invalid-error'),       
    passwordRequiredError: () => document.getElementById('password-required-error'),
}