import datetime
import PyPDF2
import pyttsx3
import pywhatkit
import speech_recognition as sr
import wikipedia
from quoters import Quote
from googlesearch import search
from googletrans import Translator
from pyMorseTranslator import translator

listener = sr.Recognizer()
engine = pyttsx3.init()
voice = engine.getProperty('voices')
engine.setProperty("rate", 178)
Translator = Translator()
search("Google")
encoder = translator.Encoder()

# Let Program return audio output


def talk(text):
    print(text)
    engine.say(text)
    engine.runAndWait()

# Function to take voice command from user


def take_command(a):
    global command
    try:
        with sr.Microphone() as source:
            talk(a)
            voice = listener.listen(source)
            command = listener.recognize_google(voice)
            command = command.lower()
            if 'jarvis' in command:
                command = command.replace('jarvis', '')
                print('> ' + command)
            else:
                print('> ' + command)
    except:
        pass
    return command

# Check for certain commands in Audio input
def run_jarvis():
    command = take_command('what can i do for you sir ?')
    if 'hello' in command:
        name = take_command('hello, whats your name ?')
        talk('hello ' + name)

    elif 'beautiful' in command:
        # command: is Ethan Beautiful
        command = command.replace('beautiful', '')
        command = command.replace('is', '')
        # command: Ethan
        if 'stephen' in command:
            talk('For sure not, Idiot')
        else:
            talk(command + ', is Beautiful Indeed')
            # Ethan is Beautiful Indeed


# Play Music on youtube
    elif 'play' in command:
        song = command.replace('play', '')
        pywhatkit.playonyt(song)
        print('playing {} ...'.format(song))
        talk('playing' + song)
# Search in Wikipedia
    elif 'what is' in command:
        try:
            command = command.replace('what is', '')
            info = wikipedia.summary(command, 1)
            talk('Searching...')
            talk(info)
        except:
            talk('No Search Results !!!!')
            pass
# Show and Read time
    elif 'time' in command:
        time = datetime.datetime.now().strftime('%I:%M %p')
        talk('It is ' + time)


# Translator
    elif 'translate' in command:
        command = command.replace('translate', '')
        command = command.replace('to', '')
        if 'arabic' in command:
            command = command.replace('arabic', '')
            translation = Translator.translate(command, dest='ar')
            print(translation.text)
        elif 'french' in command:
            command = command.replace('french', '')
            translation = Translator.translate(command, dest='fr')
            engine.setProperty('voice', voice[2].id)
            talk(translation.text)
            engine.setProperty('voice', voice[0].id)
        elif 'japanese' in command:
            command = command.replace('japanese', '')
            translation = Translator.translate(command, dest='ja')
            print(translation.text)
        elif 'code' in command:
            command = command.replace('morse', '')
            command = command.replace('code', '')
            translation = encoder.encode(command).morse
            print(translation)


# Calculator
    elif 'calculate' in command:
        command = command.replace('calculate', '')
        if '+' in command:
            numbers = command.split('+')
            total = 0
            for i in numbers:
                total = total + int(i)
            talk('It is equal to ' + str(total))

        elif '-' in command:
            numbers = command.split('-')
            total = int(numbers[0])
            for i in numbers[1:]:
                total = total - int(i)
            talk('It is equal to ' + str(total))

        elif 'x' in command:
            numbers = command.split('x')
            total = int(numbers[0])
            for i in numbers[1:]:
                total = total * int(i)
            talk('It is equal to ' + str(total))
# Quotes
    elif 'quote' in command:
        if 'serie' in command:
            try:
                quote = Quote.print_series_quote().split('―')
                talk(quote[1] + ' once Said: ' + quote[0])
            except:
                talk('Someone once Said: ' + Quote.print_series_quote())

        elif 'anime' in command:
            quote = Quote.print_anime_quote().replace('Anonymous', '')
            talk('Someone once Said at: ' + quote.replace('Reply', ''))

        elif 'programming' in command:
            try:
                quote = Quote.print_programming_quote().split('―')
                talk(quote[1] + ' once Said: ' + quote[0])
            except:
                talk('Someone once Said: ' + Quote.print_programming_quote())
        else:
            try:
                quote = Quote.print().split('―')
                talk(quote[1] + ' once Said: ' + quote[0])
            except:
                talk('Someone once Said: ' + Quote.print())

    elif 'nothing' in command:
        talk('Okay, Over')
        pass

    else:
        talk('Command not Available')

# Send Whatsapp Message
    '''
    elif 'send' in command:
        command = command.replace('send ', '')
        command = command.replace('a ', '')
        command = command.replace('message ', '')
        command = command.replace('to ', '')
    
        dict = {
            "brother": '+961*******',
        }
        a = ''
        for i in command:
            a = a + i
        if a in dict.keys():
            talk('Sending Hello to {}...'.format(a))
            pywhatkit.sendwhatmsg_instantly(dict[a], "Hello")
        else:
            talk('Contact not Available')'''


# AudioBook
    '''
    elif 'book' in command:
        command = command.replace('book', '')
        command = command.replace('read', '')
        book = open(r"",'rb')
        read = PyPDF2.PdfFileReader(book)
        pages = read.numPages
        if 'page' in command:
            page = command.replace('page', '')
            for num in range(int(page), 100):
                page = read.getPage(num)
                text = page.extract_text()
                talk(text)
        for num in range(3, 100):
            page = read.getPage(num)
            text = page.extract_text()
            talk(text)
    '''

# Main


command = 'yes'
while 'yes' in command:
    run_jarvis()
    command = take_command('Anything else Sir ?')
    if 'no' in command:
        talk('Copy that, Over')
    else:
        command = 'yes'
