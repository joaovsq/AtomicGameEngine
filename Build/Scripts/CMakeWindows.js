var fs = require('fs-extra');
var path = require("path");
var host = require("./Host");
var buildTasks = require("./BuildTasks");
var config = require("./BuildConfig");

const nodeSpawn = require('child_process').spawn;

var atomicRoot = config.atomicRoot;
var buildDir = config.artifactsRoot + "Build/Windows/";
var editorAppFolder = config.editorAppFolder

namespace('build', function() {

  // converts / to \ and removes trailing slash
  function fixpath(path) {
    return path.replace(/\//g, "\\").replace(/\\$/, "");
  }

  function getCMakeFlags() {

    // local cmake builds are always dev builds
    var flags = "-DATOMIC_DEV_BUILD=1";

    // graphics backend overrides, defaults DX11
    flags += " -DATOMIC_OPENGL=" + (config["opengl"] ? "ON" : "OFF");
    flags += " -DATOMIC_D3D11=" + (config["d3d9"] ? "OFF" : "ON");

    return flags;

  }

  // spawn cmake process
  function spawnCMake() {

    host.cleanCreateDir(atomicRoot + "/Artifacts/Build/Source/Generated");

    var slnRoot = fixpath(path.resolve(atomicRoot, "") + "-VS");

    // we're running cmd.exe, this exits the shell when the command have finished
    var args = ["/C"];

    // Windows batch file which runs cmake
    args.push(fixpath(atomicRoot + "\\Build\\Scripts\\Windows\\GenerateVSSolution.bat"));

    // Atomic root source dir
    args.push(fixpath(atomicRoot));

    // Folder to put generated solution in
    args.push(fixpath(slnRoot));

    // CMake flags
    args.push(getCMakeFlags());

    // we're using nodeSpawn here instead of jake.exec as the later was having much trouble with quotes
    var cmakeProcess = nodeSpawn("cmd.exe", args);

    cmakeProcess.stdout.on('data', (data) => {
      process.stdout.write(data.toString());
    });

    cmakeProcess.stderr.on('data', (data) => {
      process.stdout.write(data.toString());
    });

    cmakeProcess.on('exit', (code) => {

      if (code != 0) {
        fail(`CMake process exited with code ${code}`);
      }

      console.log("\n\n" + " solution created in " + fixpath(slnRoot) + "\n\n");

      complete();

    });

  }

  task('genvs', {
    async: true
  }, function() {

    spawnCMake();

  }, {
    printStdout: true,
    printStderr: true
  });

});// end of build namespace
