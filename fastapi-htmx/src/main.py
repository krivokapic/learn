from fastapi import FastAPI, Request
from fastapi.responses import HTMLResponse
from fastapi.templating import Jinja2Templates
from fastapi.staticfiles import StaticFiles
from pathlib import Path

BASE_DIR = Path(__file__).resolve().parent

app = FastAPI()
templates = Jinja2Templates(directory=BASE_DIR / "templates")
app.mount("/static", StaticFiles(directory=BASE_DIR / "static"), name="static")

@app.get("/", response_class=HTMLResponse)
async def home(request: Request):
    return templates.TemplateResponse("index.html", {"request": request})


@app.get("/htmx", response_class=HTMLResponse)
async def htmx(request: Request):
    ul = "<ul>"
    for item in list(request):
        ul += f"<li>{item}</li>"
    ul += "</ul>"

    return HTMLResponse(f"{ul}")

@app.get("/default")
async def htmx(request: Request) -> HTMLResponse:
    return HTMLResponse("""
                        <form>
                        <label for='name'>Name:</label>
                        <input type='text' id='name' name='name' value='vladimir'>
                        <label for='email'>Email:</label>
                        <input type='email' id='email' name='email' value='krivokapicvlada10@gmail.com'><br><br>
                        <input type='submit' value='Submit'>
                        <input type='submit' value='Fill out defaults' hx-get='/default' hx-target='form' hx-swap='outerHTML'>
                        <input type='submit' value='Reset' hx-get='/reset' hx-target='form' hx-swap='outerHTML'>
                        </form>
                        """)
@app.get("/reset")
async def htmx(request: Request) -> HTMLResponse:
    return HTMLResponse("""
                        <form>
                        <label for='name'>Name:</label>
                        <input type='text' id='name' name='name'>
                        <label for='email'>Email:</label>
                        <input type='email' id='email' name='email'><br><br>
                        <input type='submit' value='Submit'>
                        <input type='submit' value='Fill out defaults' hx-get='/default' hx-target='form' hx-swap='outerHTML'>
                        <input type='submit' value='Reset' hx-get='/reset' hx-target='form' hx-swap='outerHTML'>
                        </form>
                        """)
@app.get("/fill")
async def fill(request: Request) -> HTMLResponse:
    return HTMLResponse("<p>Form submitted!</p>")
