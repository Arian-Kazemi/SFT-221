function greeting(name) {
  let phrase = `Welcome, ${name}!`;

  popup(phrase);
}

function popup(phrase) {
  alert(`** ${phrase} **`);
}