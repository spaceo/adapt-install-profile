; make file
core = 7.x
api = 2

; ***********
; * MODULES *
; ***********

; admin menu
projects[admin_menu][type] = 'module'
projects[admin_menu][subdir] = 'contrib'
projects[admin_menu][version] = '3.0-rc4'

; ckeditor_link
projects[ckeditor_link][type] = 'module'
projects[ckeditor_link][subdir] = 'contrib'
projects[ckeditor_link][version] = '2.3'

; ctools
projects[ctools][type] = 'module'
projects[ctools][subdir] = 'contrib'
projects[ctools][version] = '1.3'

; entity
projects[entity][type] = 'module'
projects[entity][subdir] = 'contrib'
projects[entity][version] = '1.2'

; entityreference
projects[entityreference][type] = 'module'
projects[entityreference][subdir] = 'contrib'
projects[entityreference][version] = '1.1'

; features
projects[features][type] = 'module'
projects[features][subdir] = 'contrib'
projects[features][version] = '2.0'

; panels
projects[panels][type] = 'module'
projects[panels][subdir] = 'contrib'
projects[panels][version] = '3.3'

; pathauto
projects[pathauto][type] = 'module'
projects[pathauto][subdir] = 'contrib'
projects[pathauto][version] = '1.2'

; token
projects[token][type] = 'module'
projects[token][subdir] = 'contrib'
projects[token][version] = '1.5'

; wysiwyg
projects[wysiwyg][type] = 'module'
projects[wysiwyg][subdir] = 'contrib'
projects[wysiwyg][version] = '2.2'

; views
projects[views][type] = 'module'
projects[views][subdir] = 'contrib'
projects[views][version] = '3.7'

; xmlsitemap
projects[xmlsitemap][type] = 'module'
projects[xmlsitemap][subdir] = 'contrib'
projects[xmlsitemap][version] = '2.0-rc2'

; *************
; * LIBRARIES *
; *************

; Ckeditor
libraries[ckeditor][download][type] = get
libraries[ckeditor][download][url] = "http://download.cksource.com/CKEditor/CKEditor/CKEditor%204.3.1/ckeditor_4.3.1_standard.tar.gz"
libraries[ckeditor][destination] = libraries
libraries[ckeditor][directory_name] = ckeditor
