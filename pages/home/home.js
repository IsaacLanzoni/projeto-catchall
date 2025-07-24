async function logout() {
    
    const {error} = await supabaseClient.auth.signOut();

    if(error){
        alert(`Erro ao fazer logout: ${error.message}`);
    } else {
        window.location.href = "../login/index.html";
    }
}

async function searchUserData(){
    const {data: { user } } = await supabaseClient.auth.getUser();

    if(user){
        console.log("Usuário logado: ", user);
        const {data, error} = await supabaseClient
            .from('profiles')
            .select('*')
            .eq('id', user.id)
            .single()
    
    
        if(error){
            console.log("Erro ao buscar informações do usuário: ", error);
        } else{
            console.log("Perfil: ", data)
        }
    }
}

function showSidebar(){
    const sidebar = window.document.querySelector('.sidebar');

    sidebar.style.display = 'flex';
}

function hideSidebar(){
    const sidebar = window.document.querySelector('.sidebar');

    sidebar.style.display = 'none';
}

/*uploadButton.addEventListener('click', () => {
    form.fileSave().click();

    const importSaveButton = window.document.querySelector('.import-save-button');
    importSaveButton.style.display = 'none';

    setTimeout(() => {
        processFile();
        addSaveInformations();
        const visual = window.document.querySelector('.poke-container');
        visual.style.display = 'block';
    }, 10000);
    
});


function addSaveInformations() {
    const divPokeContainer = document.createElement('div');
    const divTexts = document.createElement('div');
    const h2 = document.createElement('h2');
    const h4I = document.createElement('h4');
    const h4II = document.createElement('h4');
    const divOwnedInfo = document.createElement('div');
    const h6I = document.createElement('h6');
    const h6II = document.createElement('h6');
    const divSeenInfo = document.createElement('div');
    const main = document.getElementById('main');
    const img = document.createElement('img');
    const imgII = document.createElement('img');


    h2.innerText = 'Pokémons';
    h4I.innerText = 'Capturados';
    h4II.innerText = 'Vistos';
    h6I.innerText = 'Charmander';
    h6II.innerText = 'Charmander';
    img.src = "https://img.pokemondb.net/sprites/sword-shield/normal/charmander.png";
    img.alt = "charmander-icon";
    imgII.src = "https://img.pokemondb.net/sprites/sword-shield/normal/charmander.png";
    imgII.alt = "charmander-icon";

    divPokeContainer.classList.add('poke-container');
    divTexts.classList.add('texts');
    h4I.classList.add('owned');
    h4II.classList.add('seen');
    divOwnedInfo.classList.add('owned-info');
    divSeenInfo.classList.add('seen-info');

    main.appendChild(divPokeContainer);
    divPokeContainer.appendChild(divTexts);
    divTexts.appendChild(h2);
    divTexts.appendChild(h4I);
    divTexts.appendChild(h4II);
    h4I.appendChild(divOwnedInfo);
    h4II.appendChild(divSeenInfo);
    divOwnedInfo.appendChild(h6I);
    divSeenInfo.appendChild(h6II);
    h6I.appendChild(imgII);
    h6II.appendChild(img);    
}


const form = {
    uploadButton: () => window.document.getElementById('uploadButton'),
    fileInput: () => window.document.getElementById('fileInput'),
    filePath: () => window.document.getElementById('filePath'),
    fileSave: () => window.document.getElementById('file-save')
}*/