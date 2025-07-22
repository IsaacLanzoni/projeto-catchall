async function onClickResetButton(){
    const email = form.email().value;

    const {data, error} = await supabaseClient.auth.resetPasswordForEmail(email, 
        {
            redirectTo: 'https://isaaclanzoni.github.io/projeto-catchall/forms/recovery/recoverpassword.html'
        }
    );
}

function onClickButton() {
    toggleEmailErrors();
}

document.addEventListener("DOMContentLoaded", function () {

    form.email().addEventListener("input", () => {
        toggleEmailErrors(); 
        toggleButtonsDisable(); 
    });

});


function onChangeEmail(){
    toggleEmailErrors();
    toggleButtonsDisable();
}


function toggleEmailErrors() {
    const email = form.email().value;

    form.emailRequiredError().style.display = email ? "none" : "block";
    form.emailInvalidError().style.display = validateEmail(email) ? "none" : "block";
}

function toggleButtonsDisable () {
    const email = form.email().value;
    const emailValid = isEmailValid();

    form.resetButton().disabled = !emailValid;

    form.resetButton().disabled = !emailValid;
}

function isEmailValid() {
    const email = form.email().value;
    if (!email){
        return false;
    }
    return validateEmail(email);
}


const form = {
    email: () => document.getElementById('reset-email-input'),
    resetButton: () => document.getElementById('reset-button'),
    emailInvalidError: () => document.getElementById('email-invalid-error'),       
    emailRequiredError: () => document.getElementById('email-required-error'),
}