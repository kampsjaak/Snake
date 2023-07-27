localisation = {}

localisation[0] = {
	"Score",
	"Punktestand",
	"Score"
}
localisation[1] = {
	"Lives",
	"Leben",
	"Levens"
}
localisation[2] = {
	"Quit",
	"Schliessen",
	"Sluiten"
}

function GetLocalisedString(key, language)
	return localisation[key][language]
end