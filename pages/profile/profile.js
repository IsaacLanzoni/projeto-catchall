const form = {
    //usernameField : () => document.querySelector(".username-field"),
    profileImage: () => document.querySelector(".profile-image"),
    main: () => document.querySelector("main"),
    email: () => document.querySelector(".email-field"),
    username: () => document.querySelector(".username"),   
    editNameInput: () => document.querySelector(".edit-name"),
    nameSwitch: () => document.querySelector('.switcher-name-button'),
    emailSwitch: () => document.querySelector('.switcher-email-button'),
    editNameButton: () => document.querySelector(".switch-button"),
    cancelEditNameButton: () => document.querySelector(".cancel-edit-name-button"),
    acceptEditNameButton: () => document.querySelector(".accept-edit-name-button"),
    newUsername: () => document.querySelector(".new-username"),
} 

document.addEventListener("DOMContentLoaded", () => {
    searchUserData();
});

async function logout() {
    
    const {error} = await supabaseClient.auth.signOut();

    if(error){
        alert(`Erro ao fazer logout: ${error.message}`);
    } else {
        window.location.href = "../../forms/login/index.html";
    }
}

async function searchUserData(){

    const main = form.main();
    const username = form.username();
    const emailField = form.email();
    const emailText = emailField.querySelector('h3');

    const {data: { user } } = await supabaseClient.auth.getUser();

    if(user){
        const {data, error} = await supabaseClient
            .from('profiles')
            .select('*')
            .eq('id', user.id)
            .single()
    
    
        if(error){
            console.log("Erro ao buscar informações do usuário: ", error);
        } else{
            username.innerText = data.name;
            emailText.innerText = user.email;
        }

        main.style.display = "block"

    }

}

form.nameSwitch().addEventListener('mouseenter', () => {
    const nameImage = form.nameSwitch().querySelector('img');
    const animation = form.nameSwitch();
    animation.classList.remove('fadeOut-animation');
    animation.classList.add('fadeIn-animation');
    nameImage.src = "../../forms/images/white_pen.png";
});

form.nameSwitch().addEventListener('mouseleave', () => {
    const nameImage = form.nameSwitch().querySelector('img');
    const animation = form.nameSwitch();
    animation.classList.remove('fadeIn-animation');
    animation.classList.add('fadeOut-animation');
    nameImage.src = "../../forms/images/edit_26dp_1E2A33_FILL0_wght400_GRAD0_opsz24.png"
});

form.emailSwitch().addEventListener('mouseenter', () => {
    const emailImage = form.emailSwitch().querySelector('img');
    const animation = form.emailSwitch();
    animation.classList.remove('fadeOut-animation');
    animation.classList.add('fadeIn-animation');
    emailImage.src = "../../forms/images/white_pen.png"
});

form.emailSwitch().addEventListener('mouseleave', () => {
    const emailImage = form.emailSwitch().querySelector('img');
    const animation = form.emailSwitch();
    animation.classList.remove('fadeIn-animation');
    animation.classList.add('fadeOut-animation');
    emailImage.src = "../../forms/images/edit_26dp_1E2A33_FILL0_wght400_GRAD0_opsz24.png"
});

form.cancelEditNameButton().addEventListener('mouseenter', () => {
    const cancelButtonImage = form.cancelEditNameButton().querySelector('img');
    const animation = form.cancelEditNameButton();
    animation.classList.add('fadeIn-animation');
    animation.classList.remove('fadeOut-animation')
    cancelButtonImage.src = "../../forms/images/cancel_icon.png"
});

form.cancelEditNameButton().addEventListener('mouseleave', () => {
    const cancelButtonImage = form.cancelEditNameButton().querySelector('img');
    const animation = form.cancelEditNameButton();
    animation.classList.remove('fadeIn-animation');
    animation.classList.add('fadeOut-animation');
    cancelButtonImage.src = "../../forms/images/cancel-icon.png"
});

form.acceptEditNameButton().addEventListener('mouseenter', () => {
    const acceptButtonImage = form.acceptEditNameButton().querySelector('img');
    const animation = form.acceptEditNameButton();
    animation.classList.add('fadeIn-animation');
    animation.classList.remove('fadeOut-animation')
    acceptButtonImage.src = "../../forms/images/accept_icon.png"
});

form.acceptEditNameButton().addEventListener('mouseleave', () => {
    const acceptButtonImage = form.acceptEditNameButton().querySelector('img');
    const animation = form.acceptEditNameButton();
    animation.classList.remove('fadeIn-animation');
    animation.classList.add('fadeOut-animation');
    acceptButtonImage.src = "../../forms/images/accept-icon.png"
});

async function editName(){
    const username = form.username();
    const cancelButton = form.cancelEditNameButton();
    const acceptButton = form.acceptEditNameButton();
    const editButton = form.editNameButton();
    const editNameInput = form.editNameInput();
    const inputElement = form.newUsername();
    
    inputElement.value = username.innerText;

    username.style.display = "none"
    cancelButton.style.display = "block"
    acceptButton.style.display = "block"
    editButton.style.display = "none"
    editNameInput.style.display = "block"

}

function cancelEditName(){
    const username = form.username();
    const cancelButton = form.cancelEditNameButton();
    const acceptButton = form.acceptEditNameButton();
    const editButton = form.editNameButton();
    const editNameInput = form.editNameInput();
    
    username.style.display = "block"
    cancelButton.style.display = "none"
    acceptButton.style.display = "none"
    editButton.style.display = "block"
    editNameInput.style.display = "none"
}

async function acceptEditName() {

    const {data: {user}, error:authError,} = await supabaseClient.auth.getUser();

    if(authError || !user){
        console.log("Erro ao tentar obter Usuário:", authError.message);
        return;
    }

    const newUsername = form.newUsername().value

    console.log(newUsername)
    if(!newUsername){
        alert("Por favor, digite um nome valido.");
        return;
    }

    const {data, error} = await supabaseClient
        .from('profiles')
        .update({ name: newUsername })
        .eq('id', user.id)
        .select();
    
    if(error){
        alert("Erro ao tentar alterar nome: ", error.message);
        return;
    } else{
        console.log("Nome alterado com sucesso: ", data);
    }

    cancelEditName();
}

function showSidebar(){
    const sidebar = window.document.querySelector('.sidebar');

    sidebar.style.display = 'flex';
}

function hideSidebar(){
    const sidebar = window.document.querySelector('.sidebar');

    sidebar.style.display = 'none';
}


