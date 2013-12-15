# Adapt install profile

## Concept
===

The Adapt Install Profile is meant to be a basis upon which new sites can be built.
It will pre-configure settings that are common for all of Adapt's developed sites.
Apart from auto-configuring a bunch of stuff it will also offer a range of optional
"features" that can be turned on depending on the project requirements, for example a slider.
It should be possible to uninstall or tweak these features during any phase of the development
process.

Roll-out: It should be possible to install the profile through a browser (install.php), but
a fully automated setup through Drush/Apache build script should also be possible.


## File / Folder structure
===

* adapt_install_profile.info: Definition of all needed modules (core, contrib & custom) that are needed
for a basic setup.
* adapt_install_profile.make: Make file
* distro.make: Distro file
* adapt_install_profile.install: Where most of the magic happens. Will include all the files in the /includes folder.

Everything included here will be executed no matter what and is not optional. All optional stuff will be packed into seperate
modules and will be available on the Basic Settings form.

* adapt_install_profile.profile: Holds the config for the Base Settings form.
* /includes: Include files. Outsourcing of logic from the .install file to keep a nice overview of
things. Everything in here is grouped in folders, each containing two files: a settings file
and an install file to execute these settings.
* /modules: All modules that are not downloaded through the build script, e.a. custom Adapt modules.
