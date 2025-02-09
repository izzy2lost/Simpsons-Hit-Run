@echo off
echo Installing dependencies...
winget install --id Rustlang.Rustup -e -h
winget install --id Git.Git -e -h
winget install --id OpenJS.NodeJS -e -h

echo Setting up Rust...
rustup default stable

echo Cloning Choreo repository...
git clone https://github.com/SleipnirGroup/Choreo.git
cd Choreo

echo Installing Node.js dependencies...
npm install

echo Building Choreo...
npm run build

echo Build complete. Run 'npm start' to launch Choreo.
pause