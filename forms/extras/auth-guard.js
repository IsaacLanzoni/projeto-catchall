supabaseClient.auth.getSession().then(({ data: { session } }) => {
  if (!session) {
    window.location.href = '../login/index.html';
  }
});


supabaseClient.auth.onAuthStateChange((event, session) => {
  if (!session) {
    window.location.href = '../login/index.html';
  }
});