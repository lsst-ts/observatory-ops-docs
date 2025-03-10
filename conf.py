from documenteer.conf.guide import *

# List of patterns, relative to source directory, that match files and
# directories to ignore when looking for source files.

exclude_patterns += ["project/Templates/Template-Folder"]
linkcheck_ignore = [
    r'http://aux-pdu-tcs.cp.lsst.org',
    r'http://pdu1-aux.cp.lsst.org', 
    r'http://pdu2-aux.cp.lsst.org',
    r'http://aux-pdu-spectrograph.cp.lsst.org', 
    r'http://aux-pdu-dome.cp.lsst.org',
    r'http://auxtel-illpdu.cp.lsst.org/.*', 
    r'http://aux-pdu-latiss.cp.lsst.org/.*',
]