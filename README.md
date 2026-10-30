# Daggerfall Online Launcher (Switch homebrew)

Opens https://daggerfall.online/ in the Switch's built-in web browser.

## Build it (pick one)

**Option A: GitHub, no installs**
1. Create a new GitHub repository and upload everything in this folder (including the `.github` folder).
2. Open the **Actions** tab. The "Build NRO" job runs automatically.
3. When it finishes, download the `DaggerfallOnline-nro` artifact and unzip it.

**Option B: Docker on your PC**
In this folder, run:
```
docker run --rm -v "${PWD}:/src" -w /src devkitpro/devkita64 make
```

**Option C: devkitPro installed locally**
Install devkitPro with the `switch-dev` group, then run `make` in this folder.

You'll get `DaggerfallOnline.nro`.

## Install and run
1. Copy `DaggerfallOnline.nro` to `/switch/` on your SD card.
2. **Hold R while launching any installed game** to open the Homebrew Menu in title-override mode.
   (Opening it from the Album won't work; the browser needs full application mode.)
3. Pick Daggerfall Online.

## Custom icon
Put a 256x256 `icon.jpg` in this folder before building.

## Caveats
- The Switch browser is old and locked down. The site may refuse to load, fail on WebGL,
  or run slowly. If so, Linux (L4T) with Chromium is the better route.
- Loading your ARENA2 files needs file upload support, which the Switch browser may lack.
- To point it at a different address, change `DFO_URL` in `source/main.c`.
