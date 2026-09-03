#!/usr/bin/env python3
from pathlib import Path
import argparse,hashlib,json,subprocess,sys

def sha(path:Path):
 h=hashlib.sha256()
 with path.open('rb') as f:
  for b in iter(lambda:f.read(1<<20),b''): h.update(b)
 return h.hexdigest()

def main():
 ap=argparse.ArgumentParser()
 ap.add_argument('--project',type=Path,required=True)
 ap.add_argument('--rom',type=Path,required=True)
 ap.add_argument('--starter-zip',type=Path,required=True)
 ap.add_argument('--oracle-zip',type=Path,required=True)
 ap.add_argument('--certificate',type=Path,default=None,help='certificate JSON; defaults to config/accepted-predecessor-certificate.json')
 a=ap.parse_args(); p=a.project.resolve()
 cert=a.certificate.resolve() if a.certificate else p/'config/accepted-predecessor-certificate.json'
 c=json.loads(cert.read_text())
 errors=[]
 git_mode='source-package-hash-only'
 if (p/'.git').exists():
  git_mode='git-tag-and-hash'
  try:
   got_commit=subprocess.check_output(['git','-C',str(p),'rev-parse',c['git_tag']+'^{commit}'],text=True,stderr=subprocess.STDOUT).strip()
  except subprocess.CalledProcessError as e:
   errors.append(f"unable to verify predecessor Git tag {c['git_tag']}: {e.output.strip()}")
  else:
   if got_commit!=c['git_commit']: errors.append(f"tag commit {got_commit} != {c['git_commit']}")
 for label,path,expected in [
  ('ROM',a.rom,c['canonical_rom_sha256']),('Starter',a.starter_zip,c['starter_zip_sha256']),('Oracle',a.oracle_zip,c['oracle_zip_sha256'])]:
  got=sha(path)
  if got!=expected: errors.append(f"{label} SHA-256 {got} != {expected}")
 for rel,expected in c['files'].items():
  path=p/rel
  if not path.is_file(): errors.append(f"missing {rel}"); continue
  got=sha(path)
  if got!=expected: errors.append(f"{rel} SHA-256 {got} != {expected}")
 if errors:
  print('PREDECESSOR CERTIFICATE: FAIL')
  print('\n'.join(errors))
  return 1
 print(f"PREDECESSOR CERTIFICATE: PASS mode={git_mode} tag={c['git_tag']} commit={c['git_commit']} files={len(c['files'])}")
 return 0
if __name__=='__main__': raise SystemExit(main())
